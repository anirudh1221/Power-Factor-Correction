

/**
 * main.c
 */

#include "F28x_Project.h"

void main(void)
{

    InitSysCtrl();   //initiates PLL
    DINT;//disable interrupts
    InitPieCtrl();
    IER = 0x0000;  //setting interrupts to zero
    IFR = 0x0000;   //setting flags to zero
    InitPieVectTable();

    EINT; //enable interrupt
    ERTM; //enable routine timer

    EALLOW;
    GpioCtrlRegs.GPBDIR.bit.GPIO34=1;    //sets input(0) or output(1)
    GpioCtrlRegs.GPBGMUX1.bit.GPIO34=0;  // configuring gpio or any type of pin mux1-0-15, mux2-16-31, 34 is 0-15 of portB so mux1 last 2 bits(MSB)
    GpioCtrlRegs.GPBMUX1.bit.GPIO34=0;   //2 LSB bits
    GpioCtrlRegs.GPBCSEL1.bit.GPIO34=0;  // to assure that only cpu1 is working
    EDIS;



    while(1)
    {
        GpioDataRegs.GPBSET.bit.GPIO34=1;      //gpbset means o/p 0 coz of invertor(buffer) setting it to 1 means making it work cant set to 0, wont work
        DELAY_US(500000);                      //delay in microseconds
        GpioDataRegs.GPBCLEAR.bit.GPIO34=1;  //gpbset means o/p 1 coz of invertor(buffer)
        DELAY_US(2000000);

    }

}
