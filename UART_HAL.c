#include "UART_HAL.h"

//initialize (used when config changes)
void initUART(uint32_t moduleInstance, const eUSCI_UART_Config *uartConfig, uint_fast8_t selectedPort, uint_fast16_t selectedPins){
    UART_initModule(moduleInstance, uartConfig);
    UART_enableModule(moduleInstance);
    GPIO_setAsPeripheralModuleFunctionInputPin(selectedPort, selectedPins, GPIO_PRIMARY_MODULE_FUNCTION);
}

//if we are receiving a character, return true
bool hasChar(){
    if (UART_getInterruptStatus(EUSCI_A0_BASE, EUSCI_A_UART_RECEIVE_INTERRUPT_FLAG) == EUSCI_A_UART_RECEIVE_INTERRUPT_FLAG){
     return true;
    }
    else{
     return false;
    }
}
