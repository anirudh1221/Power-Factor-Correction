

/**
 * main.c
 */

//#include "F28x_Project.h"
//
//void main(void)
//{
//
//    InitSysCtrl();   //initiates PLL
//    DINT;//disable interrupts
//    InitPieCtrl();
//    IER = 0x0000;  //setting interrupts to zero
//    IFR = 0x0000;   //setting flags to zero
//    InitPieVectTable();
//
//    EINT; //enable interrupt
//    ERTM; //enable routine timer
//
//    EALLOW;
//    GpioCtrlRegs.GPBDIR.bit.GPIO34=1;    //sets input(0) or output(1)
//    GpioCtrlRegs.GPBGMUX1.bit.GPIO34=0;  // configuring gpio or any type of pin mux1-0-15, mux2-16-31, 34 is 0-15 of portB so mux1 last 2 bits(MSB)
//    GpioCtrlRegs.GPBMUX1.bit.GPIO34=0;   //2 LSB bits
//    GpioCtrlRegs.GPBCSEL1.bit.GPIO34=0;  // to assure that only cpu1 is working
//    EDIS;
//
//
//
//    while(1)
//    {
//        GpioDataRegs.GPBSET.bit.GPIO34=1;      //gpbset means o/p 0 coz of invertor(buffer) setting it to 1 means making it work cant set to 0, wont work
//        DELAY_US(500000);                      //delay in microseconds
//        GpioDataRegs.GPBCLEAR.bit.GPIO34=1;  //gpbset means o/p 1 coz of invertor(buffer)
//        DELAY_US(2000000);
//
//    }
//
//}
//
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
   GpioCtrlRegs.GPADIR.bit.GPIO11=1;
   GpioCtrlRegs.GPAMUX1.bit.GPIO11=0;
   GpioCtrlRegs.GPAGMUX1.bit.GPIO11=0;
   GpioCtrlRegs.GPACSEL2.bit.GPIO11=0;

   GpioCtrlRegs.GPADIR.bit.GPIO16=1;
   GpioCtrlRegs.GPAMUX2.bit.GPIO16=0;
   GpioCtrlRegs.GPAGMUX2.bit.GPIO16=0;
   GpioCtrlRegs.GPACSEL3.bit.GPIO16=0;

   GpioCtrlRegs.GPBDIR.bit.GPIO35=1;
   GpioCtrlRegs.GPBMUX1.bit.GPIO35=3;
   GpioCtrlRegs.GPBGMUX1.bit.GPIO35=0;
   GpioCtrlRegs.GPBCSEL1.bit.GPIO35=0;

   GpioCtrlRegs.GPBDIR.bit.GPIO57=1;
   GpioCtrlRegs.GPBMUX2.bit.GPIO57=0;
   GpioCtrlRegs.GPBGMUX2.bit.GPIO57=0;
   GpioCtrlRegs.GPBCSEL4.bit.GPIO57=0;

   EDIS;

   while(1){
    GpioDataRegs.GPASET.bit.GPIO11=1;
    DELAY_US(1000000);
    GpioDataRegs.GPACLEAR.bit.GPIO11=1;
    //delay(1000000);
    GpioDataRegs.GPASET.bit.GPIO16=1;
    DELAY_US(2000000);
    GpioDataRegs.GPACLEAR.bit.GPIO16=1;
    DELAY_US(2000000);
//    GpioDataRegs.GPBCLEAR.bit.GPIO35=1;
//    DELAY_US(3000000);
//    GpioDataRegs.GPBSET.bit.GPIO35=1;
//    //delay(3000000);
//    GpioDataRegs.GPBCLEAR.bit.GPIO57=1;
//    DELAY_US(4000000);
//    GpioDataRegs.GPBSET.bit.GPIO57=1;
   // delay(4000000);
   }
    }


// End of File
//
