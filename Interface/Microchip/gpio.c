/* ************************************************************************** */
/** Descriptive File Name

  @Company
    Company Name

  @File Name
    filename.c

  @Summary
    Brief description of the file.

  @Description
    Describe the purpose of this file.
 */
/* ************************************************************************** */

/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
/* ************************************************************************** */

#include "gpioInterface.h"


/* ************************************************************************** */
/* ************************************************************************** */
/* Section: File Scope or Global Data                                         */
/* ************************************************************************** */
/* ************************************************************************** */

int global_data;

stGpioPin asGpioPins[] = 
{
    {GPIO_PORT_A,0},
    {GPIO_PORT_A,1},
}


/* ************************************************************************** */
/* ************************************************************************** */
// Section: Local Functions                                                   */
/* ************************************************************************** */
/* ************************************************************************** */

static int ExampleLocalFunction(int param1, int param2) {
    return 0;
}


/* ************************************************************************** */
/* ************************************************************************** */
// Section: Interface Functions                                               */
/* ************************************************************************** */
/* ************************************************************************** */
uint8_t gpioInterface_readGpioPin(eGpioPin GpioPin)
{
    return (GPIO_PortRead(asGpioPins[GpioPin].port)&(0x01<<asGpioPins[GpioPin].pinNo);
}

void gpioInterface_SetGpioPin(eGpioPin GpioPin)
{
    GPIO_PortSet((asGpioPins[GpioPin].port), (0x01<<(asGpioPins[GpioPin].pinNo)));
}

void gpioInterface_ResetGpioPin(eGpioPin GpioPin)
{
    void GPIO_PortClear((asGpioPins[GpioPin].port), (0x01<<(asGpioPins[GpioPin].pinNo)));
}

void gpioInterface_ToggleGpioPin(eGpioPin GpioPin)
{
    void GPIO_PortToggle((asGpioPins[GpioPin].port), (0x01<<(asGpioPins[GpioPin].pinNo)));
}

/* *****************************************************************************
 End of File
 */