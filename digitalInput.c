#include "digitalInput.h"

uint32_t debounceDelay = 10;
uint32_t longPressDelay = 500;

bool shortPressDisable = false;
bool longPressDisable = false;
bool doublePressDisable = false;

uint32_t currentTimeStamp()
{
    #ifdef FRAMEWORK_ARDUINO
        return millis();
    #endif

    #ifdef FRAMEWORK_STM32CUBE_HAL
        return HAL_GetTick();
    #endif
}

void digitalsInput(digitalInput_t *inputs) 
{
    for (int i = 0; i < INPUT_COUNT; i++)
    {
        uint32_t now = currentTimeStamp();
        inputs[i].shortPressed = false;
        inputs[i].longPressed = false;
        if(inputs[i].pinState != inputs[i].lastGlitchPinState)
        {
            inputs[i].lastPressed = now;
            inputs[i].lastGlitchPinState = inputs[i].pinState; 
        }
        if((now - inputs[i].lastPressed) > debounceDelay)
        {
            if(inputs[i].lastPinState == (false ^ inputs[i].level) && inputs[i].pinState == (true ^ inputs[i].level))
            {
                inputs[i].pressed = true;
            }
            if(inputs[i].lastPinState == (true ^ inputs[i].level) && inputs[i].pinState == (false ^ inputs[i].level))
            {
                inputs[i].pressed = false;
                longPressDisable = false;
                shortPressDisable = false;
                doublePressDisable = false;
            }
            inputs[i].lastPinState = inputs[i].pinState;
        }
        if(!(shortPressDisable))
        {
            if(inputs[i].pressed && (now - inputs[i].lastPressed) <= longPressDelay)
            {
                inputs[i].shortPressed = true;
            }
            shortPressDisable = inputs[i].shortPressed; 
        }
        if(!(longPressDisable))
        {
            if(inputs[i].pressed && (now - inputs[i].lastPressed) > longPressDelay)
            {
                inputs[i].longPressed = true;
            }
            longPressDisable = inputs[i].longPressed; 
        }
    }
}
