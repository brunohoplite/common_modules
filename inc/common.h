//
// common.h
//
// Author: Bruno Malli
// All rights reserved.
//

#pragma once

#include <stdbool.h>

// Utilities

#define ARRAY_SIZE(_x) (sizeof(_x)/sizeof(_x[0]))

// Common types and functions adapted to mcu family

#ifdef USE_HAL_DRIVER

#ifdef STM32G030xx
#include "stm32g0xx_hal.h"
#endif

typedef GPIO_TypeDef GpioPort;

#define GPIO_HIGH    GPIO_PIN_SET
#define GPIO_LOW    GPIO_PIN_RESET

#define GetTick()    HAL_GetTick()
#define GpioWritePin(_x, _y, _z)    HAL_GPIO_WritePin(_x, _y, _z)
#define GpioTogglePin(_x, _y)    HAL_GPIO_TogglePin(_x, _y)
#endif
