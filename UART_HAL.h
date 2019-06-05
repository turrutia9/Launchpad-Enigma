#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
#include <ti/grlib/grlib.h>

#define day_EASY 24000000
#define day_MED 14400000
#define day_HARD 8000000

typedef enum{ easy, medium, hard } difficulty;

void cycleDifficulty(difficulty *difficulty, eUSCI_UART_Config *uartConfig, uint32_t *timerCount, int8_t *difficultyString);
void initUART(uint32_t moduleInstance, const eUSCI_UART_Config *uartConfig, uint_fast8_t selectedPort, uint_fast16_t selectedPins);
bool hasChar();
