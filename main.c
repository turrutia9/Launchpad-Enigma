#include "LcdDriver/Crystalfontz128x128_ST7735.h"
#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
#include <ti/grlib/grlib.h>

#include "UART_HAL.h"
#include "graphics_HAL.h"

void initialize(eUSCI_UART_Config* uartConfig);

int main(void){
    Graphics_Context g_sContext;
    eUSCI_UART_Config uartConfig = {EUSCI_A_UART_CLOCKSOURCE_SMCLK, 312, 8, 0x55, EUSCI_A_UART_NO_PARITY, EUSCI_A_UART_LSB_FIRST, EUSCI_A_UART_ONE_STOP_BIT, EUSCI_A_UART_MODE, EUSCI_A_UART_OVERSAMPLING_BAUDRATE_GENERATION};
    initialize(&uartConfig);
    InitGraphics(&g_sContext);

    Graphics_drawString(&g_sContext, (int8_t*)"Enigma machine", -1, 15, 15, true);
    while(1){

    }
}

void initialize(eUSCI_UART_Config *uartConfig){
    // stop the watchdog timer
    WDT_A_hold(WDT_A_BASE);

    // call your intialization functions
    initUART(EUSCI_A0_BASE, uartConfig, GPIO_PORT_P1, GPIO_PIN2 | GPIO_PIN3);
}
