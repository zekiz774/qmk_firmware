# MCU name
MCU = STM32F401

# Bootloader selection
BOOTLOADER = stm32-dfu

# Build Options
#   comment out to disable the options.
#
MOUSEKEY_ENABLE ?= yes	# Mouse keys(+4700)
EXTRAKEY_ENABLE ?= yes	# Audio control and System control(+450)
NKRO_ENABLE ?= yes		# USB Nkey Rollover - if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
BACKLIGHT_ENABLE ?= no  # Enable keyboard backlight functionality
CONSOLE_ENABLE = yes
SPLIT_KEYBOARD = yes
TAP_DANCE_ENABLE = yes
COMBO_ENABLE = yes