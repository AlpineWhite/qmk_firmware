#define HS_RGB_BLINK_INDEX_WIN              53
#define HS_RGB_BLINK_INDEX_MAC              54
#define CAPS_LOCK_LED_INDEX                 52

/* rgb_record */
#define ENABLE_RGB_MATRIX_RGBR_PLAY
#define RGBREC_CHANNEL_NUM         4
#define EECONFIG_CONFINFO_USE_SIZE 4
#define EECONFIG_RGBREC_USE_SIZE   (RGBREC_CHANNEL_NUM * MATRIX_ROWS * MATRIX_COLS * 2)
#define EECONFIG_USER_DATA_SIZE    (EECONFIG_CONFINFO_USE_SIZE + EECONFIG_RGBREC_USE_SIZE)
#define CONFINFO_EECONFIG_ADDR     (uint32_t *)(eeconfig_update_user_datablock)
#define RGBREC_EECONFIG_ADDR       (uint8_t *)((uint32_t)eeconfig_update_user_datablock + (uint32_t)EECONFIG_CONFINFO_USE_SIZE)
#define RGB_MATRIX_DEFAULT_ON true // Sets the default enabled state, if none has been set
#define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_SOLID_COLOR
#define RGB_MATRIX_DEFAULT_HUE 0 // Sets the default hue value, if none has been set
#define RGB_MATRIX_DEFAULT_SAT 0 // Sets the default saturation value, if none has been set
#define RGB_MATRIX_DEFAULT_VAL 50 // Sets the default brightness value, if none has been set
