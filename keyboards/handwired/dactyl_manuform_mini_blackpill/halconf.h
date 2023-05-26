#pragma once

#define HAL_USE_PWM TRUE
#define HAL_USE_SERIAL TRUE
#undef SERIAL_USB_BUFFERS_SIZE
#define SERIAL_USB_BUFFERS_SIZE 256

#include_next <halconf.h>