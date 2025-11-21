#define DYNAMIC_KEYMAP_LAYER_COUNT 8 //定义VIA层数

#ifdef ENCODER_ENABLE 
#define ENCODER_DIRECTION_FLIP
# define ENCODERS_PAD_A     { B8 }
#define  ENCODERS_PAD_B     { B9 }
#define ENCODER_RESOLUTIONS { 4}/** 旋钮步进，QMK BUG 不要设置 ENCODER_RESOLUTION */
#define ENCODERS_MATRIX_MAP {{{0, 3}, {1, 3}}}
// #   define ENCODERS_TYPE_EC11
#endif
