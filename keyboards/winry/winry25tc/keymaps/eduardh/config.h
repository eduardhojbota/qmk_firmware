#pragma once

#define RGB_MATRIX_LED_COUNT 33
#define KEY_LED_COUNT 25

#define USB_SUSPEND_WAKEUP_DELAY 0
#define LAYER_STATE_8BIT
#define RGB_MATRIX_STARTUP_SPD 60

#define USB_MAX_POWER_CONSUMPTION 500

#ifdef RGB_MATRIX_ENABLE
#   define RGB_DISABLE_WHEN_USB_SUSPENDED // turn off effects when suspended
#   define RGB_MATRIX_MAXIMUM_BRIGHTNESS 150 // Limit to vendor-recommended value
#endif
