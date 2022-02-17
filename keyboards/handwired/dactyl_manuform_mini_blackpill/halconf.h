#pragma once

#define HAL_USE_PWM TRUE

#define HAL_USE_SERIAL TRUE

#define STM32_SERIAL_USE_USARTn TRUE

#define SERIAL_USB_BUFFERS_SIZE 256

#include_next <halconf.h>