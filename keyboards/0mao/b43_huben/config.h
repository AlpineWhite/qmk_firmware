#ifdef ENCODER_ENABLE
# define ENCODERS_PAD_A     { C13 }
#define  ENCODERS_PAD_B     { C14 }
#define ENCODER_RESOLUTIONS { 4}/** 旋钮步进，QMK BUG 不要设置 ENCODER_RESOLUTION */
#define ENCODERS_MATRIX_MAP {{{1, 2}, {0, 2}}}
// #   define ENCODERS_TYPE_EC11
#endif
