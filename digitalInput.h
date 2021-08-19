#pragma once
#include <stdint.h>
#include <stdbool.h> 

#define INPUT_COUNT 10 /* define the number of inputs */

#define FRAMEWORK_ARDUINO /* define the used framework */
//#define FRAMEWORK_STM32CUBE_HAL

typedef struct
{
    uint32_t lastPressed;
    bool pinState;
    bool lastPinState;
    bool lastGlitchPinState;
    bool pressed;
    bool shortPressed;
    bool longPressed;
    bool doublePressed;
    bool level; /* Active high or low level of the input */
}digitalInput_t;

void digitalInput(digitalInput_t *inputs);
