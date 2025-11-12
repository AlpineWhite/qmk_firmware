#VIA_ENABLE = yes
# Enable RGB record functionality for default keymap only
RGB_RECORD_ENABLE = yes

# Enable Dip Switch Functionality
DIP_SWITCH_ENABLE = yes

# Define the preprocessor flag
OPT_DEFS += -DRGB_RECORD_ENABLE

ENCODER_MAP_ENABLE = yes

WIRELESS_ENABLE = yes


SRC += ./rgb_record/rgb_record.c
