#include "xparameters.h"
#include "xgpio.h"
#include "xutil.h"

//====================================================

int main (void) 
{

   XGpio dip, push;
	int i, psb_check, dip_check;
	// define instance pointer for LEDs_8Bit device
	XGpio LEDs8_Bit;

   xil_printf("-- Start of the Program --\r\n");
 
   XGpio_Initialize(&dip, XPAR_DIP_DEVICE_ID);
	XGpio_SetDataDirection(&dip, 1, 0xffffffff);
	
	XGpio_Initialize(&push, XPAR_PUSH_DEVICE_ID);
	XGpio_SetDataDirection(&push, 1, 0xffffffff);
	
	// initialize and set data direction for LEDs_8Bit device
	XGpio_Initialize(&LEDs8_Bit, XPAR_LEDS_8BIT_DEVICE_ID);
	XGpio_SetDataDirection(&LEDs8_Bit, 1, 0x0);
	xil_printf("Daniel Patino 4902044");
	while (1)
	{
	  psb_check = XGpio_DiscreteRead(&push, 1);
	  xil_printf("Push Buttons Status %x\r\n", psb_check);
	  dip_check = XGpio_DiscreteRead(&dip, 1);
	  xil_printf("DIP Switch Status %x\r\n", dip_check);
	  
	  // output dip switches value on LEDs_8Bit device
	  XGpio_DiscreteWrite(&LEDs8_Bit, 1, dip_check);
	  for (i=0; i<999999; i++);
	}
}
