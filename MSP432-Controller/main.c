#include "msp.h"
#include "driverlib.h"
#include <stdio.h>


/**
 * main.c
 */

volatile int receive_var[4];
volatile int receive_var_array[4];
volatile uint32_t receive_index = 0;
volatile uint32_t receive_array_index = 0;

const eUSCI_SPI_SlaveConfig slaveConfig =
{
     EUSCI_SPI_MSB_FIRST,
     EUSCI_SPI_PHASE_DATA_CHANGED_ONFIRST_CAPTURED_ON_NEXT,
     EUSCI_SPI_CLOCKPOLARITY_INACTIVITY_LOW,
     EUSCI_SPI_3PIN

};


void main(void)
{


    WDT_A_holdTimer();
    Interrupt_disableMaster();

    unsigned int dcoFreq = 500000;
    CS_setDCOFrequency(dcoFreq);
    // Set up Sub-Master Clock
    CS_initClockSignal(CS_MCLK, CS_DCOCLK_SELECT, CS_CLOCK_DIVIDER_1);

    GPIO_setAsInputPin(GPIO_PORT_P2, GPIO_PIN6);

    GPIO_setAsPeripheralModuleFunctionInputPin(GPIO_PORT_P1, GPIO_PIN5, GPIO_PRIMARY_MODULE_FUNCTION);
    GPIO_setAsPeripheralModuleFunctionInputPin(GPIO_PORT_P1, GPIO_PIN6, GPIO_PRIMARY_MODULE_FUNCTION);
    GPIO_setAsPeripheralModuleFunctionInputPin(GPIO_PORT_P1, GPIO_PIN7, GPIO_PRIMARY_MODULE_FUNCTION);

    SPI_initSlave(EUSCI_B0_BASE, &slaveConfig);
    //I2C_setMode(EUSCI_B1_BASE, EUSCI_B_I2C_RECEIVE_MODE);
    SPI_enableModule(EUSCI_B0_BASE);
    SPI_enableInterrupt(EUSCI_B0_BASE, EUSCI_B_SPI_RECEIVE_INTERRUPT);
    Interrupt_enableInterrupt(INT_EUSCIB0);
    Interrupt_enableSleepOnIsrExit();
    Interrupt_enableMaster();

    //

    while(1){

        //printf("Infinite\n");

        SPI_enableInterrupt(EUSCI_B0_BASE, EUSCI_B_SPI_RECEIVE_INTERRUPT);
        Interrupt_enableInterrupt(INT_EUSCIB0);
        Interrupt_enableSleepOnIsrExit();
        Interrupt_enableMaster();

      //  I2C_enableInterrupt(EUSCI_B1_BASE, EUSCI_B_I2C_RECEIVE_INTERRUPT1 | EUSCI_B_I2C_NAK_INTERRUPT);
      //  Interrupt_enableInterrupt(INT_EUSCIB1);
      //  Interrupt_enableSleepOnIsrExit();
      //  Interrupt_enableMaster();


      //  printf("%i %i \n", I2C_slaveGetData(EUSCI_B1_BASE));

      //  UCB1IFG &= ~UCRXIFG;






    }



}

void EUSCIB0_IRQHandler(void){

    while(EUSCI_B_SPI_RECEIVE_INTERRUPT & SPI_getEnabledInterruptStatus(EUSCI_B0_BASE)){
        receive_var[receive_index++] = SPI_receiveData(EUSCI_B0_BASE);
       // printf("Data: %x \n", SPI_receiveData(EUSCI_B0_BASE));
    }
  //  int i = 0;

    //printf("Data: %d \n", receive_var[0]);

    receive_var_array[receive_array_index] = receive_var[0];
   // printf("%d \n", receive_array_index);
   // printf("DataArray: %d \n", receive_var[receive_array_index]);
    receive_array_index = receive_array_index+1;
 //   for (i=0;i<receive_index+1; i++){
    //    printf("Data: %x \n", receive_var[i]);
  //      printf("Data: %d \n", receive_var[i]);
  //  }

    //receive_var[4] = "";
    memset(&receive_var, '\0', sizeof(receive_var));
    receive_index = 0;

    SPI_clearInterruptFlag(EUSCI_B0_BASE, SPI_getEnabledInterruptStatus(EUSCI_B0_BASE));
    Interrupt_disableSleepOnIsrExit();

    if (receive_array_index == 4){
        printf("%d %d\n", ((receive_var_array[0]*256)+receive_var_array[1]), ((receive_var_array[2]*256)+ receive_var_array[3]));
        memset(&receive_var_array, '\0', sizeof(receive_var_array));
        receive_array_index = 0;


   //

   //
    }






}
