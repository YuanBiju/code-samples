#include <stdio.h>
#include <string.h>

#define CMD_SIZE 50
#define END_CMD "END"

typedef struct _sCommand
{
    char cmd[CMD_SIZE];
    void (*fp)(char *[],int);
    struct _sCommand *subCommand;
} sCommand;

void LedCmd(char *[],int);
void MsgColorSubCmd(char *[],int);
void parseCmd(char *);
void parseSubCmd(sCommand *,char *[],int);

char str[] = "MSG CLR 2\n";

int main(void)
{
    parseCmd(str);
}

sCommand asMsgSubCommands[] = 
{
    {"CLR",MsgColorSubCmd,NULL},
    {"RAND",NULL,NULL},
    {"END",NULL,NULL}
};

sCommand asCommands[] = 
{
    {"LED",LedCmd,NULL},
    {"MSG",NULL,asMsgSubCommands},
    {"END",NULL,NULL}
};

void LedCmd(char *argv[],int argc)
{
    if(!(strcmp(*(argv+1),"ON")))
    {
        printf("%s","ON");
    }
    else if(!(strcmp(*(argv+1),"OFF")))
    {
        printf("%s","OFF");
    }
}

void MsgColorSubCmd(char *argv[],int argc)
{
    if(!(strcmp(*(argv+1),"1")))
    {
        printf("%s","RED");
    }
    else if(!(strcmp(*(argv+1),"2")))
    {
        printf("%s","Green");
    }
}

void parseCmd(char *inData)
{

    char *toks[3];
    int i=0;
    
    toks[0] = strtok(inData," ");
    toks[1] = strtok(NULL," ");
    toks[2] = strtok(NULL,"\n");

    while(strcmp(asCommands[i].cmd,END_CMD))
    {
        if(!(strcmp(toks[0],asCommands[i].cmd)))
        {
            if(asCommands[i].fp != NULL){
                asCommands[i].fp(toks,1);
            }
            else if(asCommands[i].subCommand != NULL)
            {
                parseSubCmd(asCommands[i].subCommand,toks,1);
            }
            else
            {
                printf("%s","Invalid Command");
            }
        }
        i += 1;
    }
}

void parseSubCmd(sCommand *subCommands,char *argv[],int argc)
{
    int i=0;
    
    while(strcmp(subCommands[i].cmd,END_CMD))
    {
        if(!(strcmp(*(argv+1),subCommands[i].cmd)))
        {
            if(subCommands[i].fp != NULL){
                subCommands[i].fp(argv+1,1);
            }
            else
            {
                printf("%s","Invalid Sub Command");
            }
        }
        i += 1;
    }
}
