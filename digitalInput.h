#pragma once
#include <stdint.h> 

#define INPUT_COUNT 10 /* define the number of inputs */

#define FRAMEWORK_ARDUINO /* define the used framework */
//#define FRAMEWORK_STM32CUBE_HAL

typedef struct
{
    uint32_t lastPressed = 0;
    bool pinState = true;
    bool lastPinState = true;
    bool lastGlitchPinState = true;
    bool pressed = false;
    bool shortPressed = false;
    bool longPressed = false;
    bool doublePressed = false;
    bool level = true; /* Active high or low level of the input */
}digitalInput_t;

void digitalInput(digitalInput_t *inputs);
