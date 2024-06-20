
OLED_ENABLE = yes
OLED_DRIVER = ssd1306
# ENCODER_ENABLE = yes
WPM_ENABLE = yes
# SRC += features/repeat_key.c
# SRC += features/select_word.c
SRC += features/achordion.c
COMBO_ENABLE = yes

STENO_ENABLE = yes
STENO_PROTOCOL = geminipr

# RGBLIGHT_SUPPORTED = yes
# RGB_MATRIX_SUPPORTED = yes

RGBLIGHT_ENABLE = no
RGB_MATRIX_ENABLE = yes

MOUSEKEY_ENABLE = yes # Mouse keys
EXTRAKEY_ENABLE = yes # Audio control and System control
# AUTO_SHIFT_ENABLE = yes # Auto Shift
# CAPS_WORD_ENABLE = yes
# REPEAT_KEY_ENABLE = yes


# include "quantum.h"



# Save space
LTO_ENABLE = yes 
COMMAND_ENABLE = no
MUSIC_ENABLE = no
MAGIC_ENABLE = no
SPACE_CADET_ENABLE = no
GRAVE_ESC_ENABLE = no
CONSOLE_ENABLE = no
AVR_USE_MINIMAL_PRINTF = yes
