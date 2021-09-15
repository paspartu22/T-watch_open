#include "lvgl.h"

#ifndef LV_ATTRIBUTE_MEM_ALIGN
#define LV_ATTRIBUTE_MEM_ALIGN
#endif

#ifndef LV_ATTRIBUTE_IMG_INFO_1_16PX
#define LV_ATTRIBUTE_IMG_INFO_1_16PX
#endif

const LV_ATTRIBUTE_MEM_ALIGN LV_ATTRIBUTE_IMG_INFO_1_16PX uint8_t info_1_16px_map[] = {
#if LV_COLOR_DEPTH == 1 || LV_COLOR_DEPTH == 8
  /*Pixel format: Alpha 8 bit, Red: 3 bit, Green: 3 bit, Blue: 2 bit*/
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x00, 0x18, 0x3c, 0x18, 0x9c, 0x18, 0xdb, 0x18, 0xfb, 0x18, 0xf7, 0x18, 0xd0, 0x18, 0x8b, 0x18, 0x24, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x18, 0x00, 0x18, 0x0f, 0x18, 0xac, 0x18, 0xff, 0x18, 0xff, 0x18, 0xff, 0x18, 0xff, 0x18, 0xff, 0x18, 0xff, 0x18, 0xff, 0x18, 0xfb, 0x18, 0x83, 0x18, 0x03, 0x00, 0x00, 0x00, 0x00, 
  0x04, 0x00, 0x18, 0x10, 0x18, 0xd3, 0x18, 0xff, 0x18, 0xff, 0x39, 0xff, 0x7e, 0xff, 0xbe, 0xff, 0x9e, 0xff, 0x18, 0xff, 0x18, 0xff, 0x18, 0xff, 0x18, 0xff, 0x18, 0xa7, 0x18, 0x03, 0x00, 0x00, 
  0x18, 0x00, 0x18, 0xb4, 0x18, 0xff, 0x18, 0xff, 0x59, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x18, 0xff, 0x18, 0xff, 0x18, 0xff, 0x18, 0xff, 0x18, 0xff, 0x18, 0x77, 0x18, 0x00, 
  0x18, 0x48, 0x18, 0xff, 0x18, 0xff, 0x18, 0xff, 0x38, 0xff, 0x9e, 0xff, 0x39, 0xff, 0xdf, 0xff, 0xff, 0xff, 0x18, 0xff, 0x18, 0xff, 0x18, 0xff, 0x18, 0xff, 0x18, 0xff, 0x18, 0xf7, 0x18, 0x18, 
  0x18, 0xac, 0x18, 0xff, 0x18, 0xff, 0x18, 0xff, 0x18, 0xff, 0x18, 0xff, 0x18, 0xff, 0xdf, 0xff, 0xff, 0xff, 0x18, 0xff, 0x18, 0xff, 0x18, 0xff, 0x18, 0xff, 0x18, 0xff, 0x18, 0xff, 0x18, 0x74, 
  0x18, 0xef, 0x18, 0xff, 0x18, 0xff, 0x18, 0xff, 0x18, 0xff, 0x18, 0xff, 0x18, 0xff, 0xdf, 0xff, 0xff, 0xff, 0x18, 0xff, 0x18, 0xff, 0x18, 0xff, 0x18, 0xff, 0x18, 0xff, 0x18, 0xff, 0x18, 0xb4, 
  0x18, 0xff, 0x18, 0xff, 0x18, 0xff, 0x18, 0xff, 0x18, 0xff, 0x18, 0xff, 0x18, 0xff, 0xdf, 0xff, 0xff, 0xff, 0x18, 0xff, 0x18, 0xff, 0x18, 0xff, 0x18, 0xff, 0x18, 0xff, 0x18, 0xff, 0x18, 0xd7, 
  0x18, 0xff, 0x18, 0xff, 0x18, 0xff, 0x18, 0xff, 0x18, 0xff, 0x18, 0xff, 0x18, 0xff, 0xdf, 0xff, 0xff, 0xff, 0x18, 0xff, 0x18, 0xff, 0x18, 0xff, 0x18, 0xff, 0x18, 0xff, 0x18, 0xff, 0x18, 0xd7, 
  0x18, 0xef, 0x18, 0xff, 0x18, 0xff, 0x18, 0xff, 0x18, 0xff, 0x18, 0xff, 0x18, 0xff, 0xdf, 0xff, 0xff, 0xff, 0x18, 0xff, 0x18, 0xff, 0x18, 0xff, 0x18, 0xff, 0x18, 0xff, 0x18, 0xff, 0x18, 0xb4, 
  0x18, 0xac, 0x18, 0xff, 0x18, 0xff, 0x18, 0xff, 0x18, 0xff, 0x18, 0xff, 0x18, 0xff, 0xdf, 0xff, 0xff, 0xff, 0x18, 0xff, 0x18, 0xff, 0x18, 0xff, 0x18, 0xff, 0x18, 0xff, 0x18, 0xff, 0x18, 0x74, 
  0x18, 0x48, 0x18, 0xff, 0x18, 0xff, 0x18, 0xff, 0x18, 0xff, 0x39, 0xff, 0x39, 0xff, 0xdf, 0xff, 0xff, 0xff, 0x39, 0xff, 0x39, 0xff, 0x18, 0xff, 0x18, 0xff, 0x18, 0xff, 0x18, 0xf7, 0x18, 0x18, 
  0x18, 0x00, 0x18, 0xb3, 0x18, 0xff, 0x18, 0xff, 0x18, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7e, 0xff, 0x18, 0xff, 0x18, 0xff, 0x18, 0x77, 0x18, 0x00, 
  0x04, 0x00, 0x18, 0x10, 0x18, 0xd3, 0x18, 0xff, 0x18, 0xff, 0x39, 0xff, 0x59, 0xff, 0x59, 0xff, 0x59, 0xff, 0x59, 0xff, 0x59, 0xff, 0x18, 0xff, 0x18, 0xff, 0x18, 0xa7, 0x18, 0x03, 0x00, 0x00, 
  0x00, 0x00, 0x18, 0x00, 0x18, 0x0f, 0x18, 0xac, 0x18, 0xff, 0x18, 0xff, 0x18, 0xff, 0x18, 0xff, 0x18, 0xff, 0x18, 0xff, 0x18, 0xff, 0x18, 0xfb, 0x18, 0x80, 0x18, 0x03, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x00, 0x18, 0x3c, 0x18, 0x9c, 0x18, 0xdb, 0x18, 0xfb, 0x18, 0xf7, 0x18, 0xcf, 0x18, 0x8b, 0x18, 0x24, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
#endif
#if LV_COLOR_DEPTH == 16 && LV_COLOR_16_SWAP == 0
  /*Pixel format: Alpha 8 bit, Red: 5 bit, Green: 6 bit, Blue: 5 bit*/
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x06, 0x00, 0x40, 0x06, 0x3c, 0x40, 0x06, 0x9c, 0x40, 0x06, 0xdb, 0x40, 0x06, 0xfb, 0x40, 0x06, 0xf7, 0x40, 0x06, 0xd0, 0x40, 0x06, 0x8b, 0x40, 0x06, 0x24, 0x40, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x40, 0x06, 0x00, 0x40, 0x06, 0x0f, 0x40, 0x06, 0xac, 0x40, 0x06, 0xff, 0x40, 0x06, 0xff, 0x40, 0x06, 0xff, 0x40, 0x06, 0xff, 0x40, 0x06, 0xff, 0x40, 0x06, 0xff, 0x40, 0x06, 0xff, 0x40, 0x06, 0xfb, 0x40, 0x06, 0x83, 0x40, 0x06, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x01, 0x00, 0x40, 0x06, 0x10, 0x40, 0x06, 0xd3, 0x40, 0x06, 0xff, 0x40, 0x06, 0xff, 0x44, 0x26, 0xff, 0xac, 0x66, 0xff, 0x14, 0xa7, 0xff, 0xf2, 0x96, 0xff, 0x40, 0x06, 0xff, 0x40, 0x06, 0xff, 0x40, 0x06, 0xff, 0x40, 0x06, 0xff, 0x40, 0x06, 0xa7, 0x20, 0x06, 0x03, 0x00, 0x00, 0x00, 
  0x60, 0x06, 0x00, 0x40, 0x06, 0xb4, 0x40, 0x06, 0xff, 0x40, 0x06, 0xff, 0x66, 0x36, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xbd, 0xef, 0xff, 0x40, 0x06, 0xff, 0x40, 0x06, 0xff, 0x40, 0x06, 0xff, 0x40, 0x06, 0xff, 0x40, 0x06, 0xff, 0x40, 0x06, 0x77, 0x20, 0x06, 0x00, 
  0x40, 0x06, 0x48, 0x40, 0x06, 0xff, 0x40, 0x06, 0xff, 0x40, 0x06, 0xff, 0x44, 0x26, 0xff, 0xd1, 0x8e, 0xff, 0x65, 0x2e, 0xff, 0x58, 0xc7, 0xff, 0xbd, 0xef, 0xff, 0x40, 0x06, 0xff, 0x40, 0x06, 0xff, 0x40, 0x06, 0xff, 0x40, 0x06, 0xff, 0x40, 0x06, 0xff, 0x40, 0x06, 0xf7, 0x40, 0x06, 0x18, 
  0x40, 0x06, 0xac, 0x40, 0x06, 0xff, 0x40, 0x06, 0xff, 0x40, 0x06, 0xff, 0x40, 0x06, 0xff, 0x40, 0x06, 0xff, 0x40, 0x06, 0xff, 0x58, 0xc7, 0xff, 0xbd, 0xef, 0xff, 0x40, 0x06, 0xff, 0x40, 0x06, 0xff, 0x40, 0x06, 0xff, 0x40, 0x06, 0xff, 0x40, 0x06, 0xff, 0x40, 0x06, 0xff, 0x40, 0x06, 0x74, 
  0x40, 0x06, 0xef, 0x40, 0x06, 0xff, 0x40, 0x06, 0xff, 0x40, 0x06, 0xff, 0x40, 0x06, 0xff, 0x40, 0x06, 0xff, 0x40, 0x06, 0xff, 0x58, 0xc7, 0xff, 0xbd, 0xef, 0xff, 0x40, 0x06, 0xff, 0x40, 0x06, 0xff, 0x40, 0x06, 0xff, 0x40, 0x06, 0xff, 0x40, 0x06, 0xff, 0x40, 0x06, 0xff, 0x40, 0x06, 0xb4, 
  0x40, 0x06, 0xff, 0x40, 0x06, 0xff, 0x40, 0x06, 0xff, 0x40, 0x06, 0xff, 0x40, 0x06, 0xff, 0x40, 0x06, 0xff, 0x40, 0x06, 0xff, 0x58, 0xc7, 0xff, 0xbd, 0xef, 0xff, 0x40, 0x06, 0xff, 0x40, 0x06, 0xff, 0x40, 0x06, 0xff, 0x40, 0x06, 0xff, 0x40, 0x06, 0xff, 0x40, 0x06, 0xff, 0x40, 0x06, 0xd7, 
  0x40, 0x06, 0xff, 0x40, 0x06, 0xff, 0x40, 0x06, 0xff, 0x40, 0x06, 0xff, 0x40, 0x06, 0xff, 0x40, 0x06, 0xff, 0x40, 0x06, 0xff, 0x58, 0xc7, 0xff, 0xbd, 0xef, 0xff, 0x40, 0x06, 0xff, 0x40, 0x06, 0xff, 0x40, 0x06, 0xff, 0x40, 0x06, 0xff, 0x40, 0x06, 0xff, 0x40, 0x06, 0xff, 0x40, 0x06, 0xd7, 
  0x40, 0x06, 0xef, 0x40, 0x06, 0xff, 0x40, 0x06, 0xff, 0x40, 0x06, 0xff, 0x40, 0x06, 0xff, 0x40, 0x06, 0xff, 0x40, 0x06, 0xff, 0x58, 0xc7, 0xff, 0xbd, 0xef, 0xff, 0x40, 0x06, 0xff, 0x40, 0x06, 0xff, 0x40, 0x06, 0xff, 0x40, 0x06, 0xff, 0x40, 0x06, 0xff, 0x40, 0x06, 0xff, 0x40, 0x06, 0xb4, 
  0x40, 0x06, 0xac, 0x40, 0x06, 0xff, 0x40, 0x06, 0xff, 0x40, 0x06, 0xff, 0x40, 0x06, 0xff, 0x40, 0x06, 0xff, 0x40, 0x06, 0xff, 0x58, 0xc7, 0xff, 0xbd, 0xef, 0xff, 0x40, 0x06, 0xff, 0x40, 0x06, 0xff, 0x40, 0x06, 0xff, 0x40, 0x06, 0xff, 0x40, 0x06, 0xff, 0x40, 0x06, 0xff, 0x40, 0x06, 0x74, 
  0x40, 0x06, 0x48, 0x40, 0x06, 0xff, 0x40, 0x06, 0xff, 0x40, 0x06, 0xff, 0x40, 0x06, 0xff, 0x65, 0x2e, 0xff, 0x65, 0x2e, 0xff, 0x79, 0xcf, 0xff, 0xdd, 0xef, 0xff, 0x65, 0x2e, 0xff, 0x65, 0x2e, 0xff, 0x41, 0x0e, 0xff, 0x40, 0x06, 0xff, 0x40, 0x06, 0xff, 0x40, 0x06, 0xf7, 0x40, 0x06, 0x18, 
  0x60, 0x06, 0x00, 0x40, 0x06, 0xb3, 0x40, 0x06, 0xff, 0x40, 0x06, 0xff, 0x40, 0x06, 0xff, 0xfe, 0xf7, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x8c, 0x66, 0xff, 0x40, 0x06, 0xff, 0x40, 0x06, 0xff, 0x40, 0x06, 0x77, 0x60, 0x06, 0x00, 
  0x00, 0x01, 0x00, 0x40, 0x06, 0x10, 0x40, 0x06, 0xd3, 0x40, 0x06, 0xff, 0x40, 0x06, 0xff, 0x66, 0x36, 0xff, 0x66, 0x36, 0xff, 0x66, 0x36, 0xff, 0x66, 0x36, 0xff, 0x66, 0x36, 0xff, 0x66, 0x36, 0xff, 0x42, 0x16, 0xff, 0x40, 0x06, 0xff, 0x40, 0x06, 0xa7, 0x40, 0x06, 0x03, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x40, 0x06, 0x00, 0x40, 0x06, 0x0f, 0x40, 0x06, 0xac, 0x40, 0x06, 0xff, 0x40, 0x06, 0xff, 0x40, 0x06, 0xff, 0x40, 0x06, 0xff, 0x40, 0x06, 0xff, 0x40, 0x06, 0xff, 0x40, 0x06, 0xff, 0x40, 0x06, 0xfb, 0x40, 0x06, 0x80, 0x40, 0x06, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0x06, 0x00, 0x40, 0x06, 0x3c, 0x40, 0x06, 0x9c, 0x40, 0x06, 0xdb, 0x40, 0x06, 0xfb, 0x40, 0x06, 0xf7, 0x40, 0x06, 0xcf, 0x40, 0x06, 0x8b, 0x40, 0x06, 0x24, 0x40, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
#endif
#if LV_COLOR_DEPTH == 16 && LV_COLOR_16_SWAP != 0
  /*Pixel format: Alpha 8 bit, Red: 5 bit, Green: 6 bit, Blue: 5 bit  BUT the 2  color bytes are swapped*/
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x40, 0x00, 0x06, 0x40, 0x3c, 0x06, 0x40, 0x9c, 0x06, 0x40, 0xdb, 0x06, 0x40, 0xfb, 0x06, 0x40, 0xf7, 0x06, 0x40, 0xd0, 0x06, 0x40, 0x8b, 0x06, 0x40, 0x24, 0x06, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x06, 0x40, 0x00, 0x06, 0x40, 0x0f, 0x06, 0x40, 0xac, 0x06, 0x40, 0xff, 0x06, 0x40, 0xff, 0x06, 0x40, 0xff, 0x06, 0x40, 0xff, 0x06, 0x40, 0xff, 0x06, 0x40, 0xff, 0x06, 0x40, 0xff, 0x06, 0x40, 0xfb, 0x06, 0x40, 0x83, 0x06, 0x40, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x01, 0x00, 0x00, 0x06, 0x40, 0x10, 0x06, 0x40, 0xd3, 0x06, 0x40, 0xff, 0x06, 0x40, 0xff, 0x26, 0x44, 0xff, 0x66, 0xac, 0xff, 0xa7, 0x14, 0xff, 0x96, 0xf2, 0xff, 0x06, 0x40, 0xff, 0x06, 0x40, 0xff, 0x06, 0x40, 0xff, 0x06, 0x40, 0xff, 0x06, 0x40, 0xa7, 0x06, 0x20, 0x03, 0x00, 0x00, 0x00, 
  0x06, 0x60, 0x00, 0x06, 0x40, 0xb4, 0x06, 0x40, 0xff, 0x06, 0x40, 0xff, 0x36, 0x66, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xef, 0xbd, 0xff, 0x06, 0x40, 0xff, 0x06, 0x40, 0xff, 0x06, 0x40, 0xff, 0x06, 0x40, 0xff, 0x06, 0x40, 0xff, 0x06, 0x40, 0x77, 0x06, 0x20, 0x00, 
  0x06, 0x40, 0x48, 0x06, 0x40, 0xff, 0x06, 0x40, 0xff, 0x06, 0x40, 0xff, 0x26, 0x44, 0xff, 0x8e, 0xd1, 0xff, 0x2e, 0x65, 0xff, 0xc7, 0x58, 0xff, 0xef, 0xbd, 0xff, 0x06, 0x40, 0xff, 0x06, 0x40, 0xff, 0x06, 0x40, 0xff, 0x06, 0x40, 0xff, 0x06, 0x40, 0xff, 0x06, 0x40, 0xf7, 0x06, 0x40, 0x18, 
  0x06, 0x40, 0xac, 0x06, 0x40, 0xff, 0x06, 0x40, 0xff, 0x06, 0x40, 0xff, 0x06, 0x40, 0xff, 0x06, 0x40, 0xff, 0x06, 0x40, 0xff, 0xc7, 0x58, 0xff, 0xef, 0xbd, 0xff, 0x06, 0x40, 0xff, 0x06, 0x40, 0xff, 0x06, 0x40, 0xff, 0x06, 0x40, 0xff, 0x06, 0x40, 0xff, 0x06, 0x40, 0xff, 0x06, 0x40, 0x74, 
  0x06, 0x40, 0xef, 0x06, 0x40, 0xff, 0x06, 0x40, 0xff, 0x06, 0x40, 0xff, 0x06, 0x40, 0xff, 0x06, 0x40, 0xff, 0x06, 0x40, 0xff, 0xc7, 0x58, 0xff, 0xef, 0xbd, 0xff, 0x06, 0x40, 0xff, 0x06, 0x40, 0xff, 0x06, 0x40, 0xff, 0x06, 0x40, 0xff, 0x06, 0x40, 0xff, 0x06, 0x40, 0xff, 0x06, 0x40, 0xb4, 
  0x06, 0x40, 0xff, 0x06, 0x40, 0xff, 0x06, 0x40, 0xff, 0x06, 0x40, 0xff, 0x06, 0x40, 0xff, 0x06, 0x40, 0xff, 0x06, 0x40, 0xff, 0xc7, 0x58, 0xff, 0xef, 0xbd, 0xff, 0x06, 0x40, 0xff, 0x06, 0x40, 0xff, 0x06, 0x40, 0xff, 0x06, 0x40, 0xff, 0x06, 0x40, 0xff, 0x06, 0x40, 0xff, 0x06, 0x40, 0xd7, 
  0x06, 0x40, 0xff, 0x06, 0x40, 0xff, 0x06, 0x40, 0xff, 0x06, 0x40, 0xff, 0x06, 0x40, 0xff, 0x06, 0x40, 0xff, 0x06, 0x40, 0xff, 0xc7, 0x58, 0xff, 0xef, 0xbd, 0xff, 0x06, 0x40, 0xff, 0x06, 0x40, 0xff, 0x06, 0x40, 0xff, 0x06, 0x40, 0xff, 0x06, 0x40, 0xff, 0x06, 0x40, 0xff, 0x06, 0x40, 0xd7, 
  0x06, 0x40, 0xef, 0x06, 0x40, 0xff, 0x06, 0x40, 0xff, 0x06, 0x40, 0xff, 0x06, 0x40, 0xff, 0x06, 0x40, 0xff, 0x06, 0x40, 0xff, 0xc7, 0x58, 0xff, 0xef, 0xbd, 0xff, 0x06, 0x40, 0xff, 0x06, 0x40, 0xff, 0x06, 0x40, 0xff, 0x06, 0x40, 0xff, 0x06, 0x40, 0xff, 0x06, 0x40, 0xff, 0x06, 0x40, 0xb4, 
  0x06, 0x40, 0xac, 0x06, 0x40, 0xff, 0x06, 0x40, 0xff, 0x06, 0x40, 0xff, 0x06, 0x40, 0xff, 0x06, 0x40, 0xff, 0x06, 0x40, 0xff, 0xc7, 0x58, 0xff, 0xef, 0xbd, 0xff, 0x06, 0x40, 0xff, 0x06, 0x40, 0xff, 0x06, 0x40, 0xff, 0x06, 0x40, 0xff, 0x06, 0x40, 0xff, 0x06, 0x40, 0xff, 0x06, 0x40, 0x74, 
  0x06, 0x40, 0x48, 0x06, 0x40, 0xff, 0x06, 0x40, 0xff, 0x06, 0x40, 0xff, 0x06, 0x40, 0xff, 0x2e, 0x65, 0xff, 0x2e, 0x65, 0xff, 0xcf, 0x79, 0xff, 0xef, 0xdd, 0xff, 0x2e, 0x65, 0xff, 0x2e, 0x65, 0xff, 0x0e, 0x41, 0xff, 0x06, 0x40, 0xff, 0x06, 0x40, 0xff, 0x06, 0x40, 0xf7, 0x06, 0x40, 0x18, 
  0x06, 0x60, 0x00, 0x06, 0x40, 0xb3, 0x06, 0x40, 0xff, 0x06, 0x40, 0xff, 0x06, 0x40, 0xff, 0xf7, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x66, 0x8c, 0xff, 0x06, 0x40, 0xff, 0x06, 0x40, 0xff, 0x06, 0x40, 0x77, 0x06, 0x60, 0x00, 
  0x01, 0x00, 0x00, 0x06, 0x40, 0x10, 0x06, 0x40, 0xd3, 0x06, 0x40, 0xff, 0x06, 0x40, 0xff, 0x36, 0x66, 0xff, 0x36, 0x66, 0xff, 0x36, 0x66, 0xff, 0x36, 0x66, 0xff, 0x36, 0x66, 0xff, 0x36, 0x66, 0xff, 0x16, 0x42, 0xff, 0x06, 0x40, 0xff, 0x06, 0x40, 0xa7, 0x06, 0x40, 0x03, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x06, 0x40, 0x00, 0x06, 0x40, 0x0f, 0x06, 0x40, 0xac, 0x06, 0x40, 0xff, 0x06, 0x40, 0xff, 0x06, 0x40, 0xff, 0x06, 0x40, 0xff, 0x06, 0x40, 0xff, 0x06, 0x40, 0xff, 0x06, 0x40, 0xff, 0x06, 0x40, 0xfb, 0x06, 0x40, 0x80, 0x06, 0x40, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x60, 0x00, 0x06, 0x40, 0x3c, 0x06, 0x40, 0x9c, 0x06, 0x40, 0xdb, 0x06, 0x40, 0xfb, 0x06, 0x40, 0xf7, 0x06, 0x40, 0xcf, 0x06, 0x40, 0x8b, 0x06, 0x40, 0x24, 0x06, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
#endif
#if LV_COLOR_DEPTH == 32
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xca, 0x00, 0x00, 0x00, 0xc8, 0x00, 0x3c, 0x00, 0xc8, 0x00, 0x9c, 0x00, 0xc8, 0x00, 0xdb, 0x00, 0xc8, 0x00, 0xfb, 0x00, 0xc8, 0x00, 0xf7, 0x00, 0xc8, 0x00, 0xd0, 0x00, 0xc8, 0x00, 0x8b, 0x00, 0xc8, 0x00, 0x24, 0x00, 0xc7, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0xc7, 0x00, 0x00, 0x00, 0xc9, 0x00, 0x0f, 0x00, 0xc8, 0x00, 0xac, 0x00, 0xc8, 0x00, 0xff, 0x00, 0xc8, 0x00, 0xff, 0x00, 0xc8, 0x00, 0xff, 0x00, 0xc8, 0x00, 0xff, 0x00, 0xc8, 0x00, 0xff, 0x00, 0xc8, 0x00, 0xff, 0x00, 0xc8, 0x00, 0xff, 0x00, 0xc8, 0x00, 0xfb, 0x00, 0xc8, 0x00, 0x83, 0x00, 0xc8, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x20, 0x00, 0x00, 0x00, 0xc9, 0x00, 0x10, 0x00, 0xc8, 0x00, 0xd3, 0x00, 0xc8, 0x00, 0xff, 0x00, 0xc8, 0x00, 0xff, 0x22, 0xc9, 0x22, 0xff, 0x61, 0xd3, 0x61, 0xff, 0x9e, 0xdf, 0x9e, 0xff, 0x90, 0xdc, 0x90, 0xff, 0x00, 0xc8, 0x00, 0xff, 0x00, 0xc8, 0x00, 0xff, 0x00, 0xc8, 0x00, 0xff, 0x00, 0xc8, 0x00, 0xff, 0x00, 0xc8, 0x00, 0xa7, 0x00, 0xc6, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0xcb, 0x00, 0x00, 0x00, 0xc8, 0x00, 0xb4, 0x00, 0xc8, 0x00, 0xff, 0x00, 0xc8, 0x00, 0xff, 0x33, 0xcd, 0x33, 0xff, 0xf6, 0xfd, 0xf6, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfa, 0xfe, 0xfa, 0xff, 0xe7, 0xf6, 0xe7, 0xff, 0x00, 0xc8, 0x00, 0xff, 0x00, 0xc8, 0x00, 0xff, 0x00, 0xc8, 0x00, 0xff, 0x00, 0xc8, 0x00, 0xff, 0x00, 0xc8, 0x00, 0xff, 0x00, 0xc8, 0x00, 0x77, 0x00, 0xc6, 0x00, 0x00, 
  0x00, 0xc8, 0x00, 0x48, 0x00, 0xc8, 0x00, 0xff, 0x00, 0xc8, 0x00, 0xff, 0x00, 0xc8, 0x00, 0xff, 0x20, 0xca, 0x20, 0xff, 0x88, 0xda, 0x88, 0xff, 0x29, 0xcd, 0x29, 0xff, 0xc2, 0xe9, 0xc2, 0xff, 0xe7, 0xf6, 0xe7, 0xff, 0x00, 0xc8, 0x00, 0xff, 0x00, 0xc8, 0x00, 0xff, 0x00, 0xc8, 0x00, 0xff, 0x00, 0xc8, 0x00, 0xff, 0x00, 0xc8, 0x00, 0xff, 0x00, 0xc8, 0x00, 0xf7, 0x00, 0xc8, 0x00, 0x18, 
  0x00, 0xc8, 0x00, 0xac, 0x00, 0xc8, 0x00, 0xff, 0x00, 0xc8, 0x00, 0xff, 0x00, 0xc8, 0x00, 0xff, 0x00, 0xc8, 0x00, 0xff, 0x00, 0xc8, 0x00, 0xff, 0x00, 0xc8, 0x00, 0xff, 0xc3, 0xe9, 0xc3, 0xff, 0xe7, 0xf6, 0xe7, 0xff, 0x00, 0xc8, 0x00, 0xff, 0x00, 0xc8, 0x00, 0xff, 0x00, 0xc8, 0x00, 0xff, 0x00, 0xc8, 0x00, 0xff, 0x00, 0xc8, 0x00, 0xff, 0x00, 0xc8, 0x00, 0xff, 0x00, 0xc8, 0x00, 0x74, 
  0x00, 0xc8, 0x00, 0xef, 0x00, 0xc8, 0x00, 0xff, 0x00, 0xc8, 0x00, 0xff, 0x00, 0xc8, 0x00, 0xff, 0x00, 0xc8, 0x00, 0xff, 0x00, 0xc8, 0x00, 0xff, 0x00, 0xc8, 0x00, 0xff, 0xc3, 0xe9, 0xc3, 0xff, 0xe7, 0xf6, 0xe7, 0xff, 0x00, 0xc8, 0x00, 0xff, 0x00, 0xc8, 0x00, 0xff, 0x00, 0xc8, 0x00, 0xff, 0x00, 0xc8, 0x00, 0xff, 0x00, 0xc8, 0x00, 0xff, 0x00, 0xc8, 0x00, 0xff, 0x00, 0xc8, 0x00, 0xb4, 
  0x00, 0xc8, 0x00, 0xff, 0x00, 0xc8, 0x00, 0xff, 0x00, 0xc8, 0x00, 0xff, 0x00, 0xc8, 0x00, 0xff, 0x00, 0xc8, 0x00, 0xff, 0x00, 0xc8, 0x00, 0xff, 0x00, 0xc8, 0x00, 0xff, 0xc3, 0xe9, 0xc3, 0xff, 0xe7, 0xf6, 0xe7, 0xff, 0x00, 0xc8, 0x00, 0xff, 0x00, 0xc8, 0x00, 0xff, 0x00, 0xc8, 0x00, 0xff, 0x00, 0xc8, 0x00, 0xff, 0x00, 0xc8, 0x00, 0xff, 0x00, 0xc8, 0x00, 0xff, 0x00, 0xc8, 0x00, 0xd7, 
  0x00, 0xc8, 0x00, 0xff, 0x00, 0xc8, 0x00, 0xff, 0x00, 0xc8, 0x00, 0xff, 0x00, 0xc8, 0x00, 0xff, 0x00, 0xc8, 0x00, 0xff, 0x00, 0xc8, 0x00, 0xff, 0x00, 0xc8, 0x00, 0xff, 0xc3, 0xe9, 0xc3, 0xff, 0xe7, 0xf6, 0xe7, 0xff, 0x00, 0xc8, 0x00, 0xff, 0x00, 0xc8, 0x00, 0xff, 0x00, 0xc8, 0x00, 0xff, 0x00, 0xc8, 0x00, 0xff, 0x00, 0xc8, 0x00, 0xff, 0x00, 0xc8, 0x00, 0xff, 0x00, 0xc8, 0x00, 0xd7, 
  0x00, 0xc8, 0x00, 0xef, 0x00, 0xc8, 0x00, 0xff, 0x00, 0xc8, 0x00, 0xff, 0x00, 0xc8, 0x00, 0xff, 0x00, 0xc8, 0x00, 0xff, 0x00, 0xc8, 0x00, 0xff, 0x00, 0xc8, 0x00, 0xff, 0xc3, 0xe9, 0xc3, 0xff, 0xe7, 0xf6, 0xe7, 0xff, 0x00, 0xc8, 0x00, 0xff, 0x00, 0xc8, 0x00, 0xff, 0x00, 0xc8, 0x00, 0xff, 0x00, 0xc8, 0x00, 0xff, 0x00, 0xc8, 0x00, 0xff, 0x00, 0xc8, 0x00, 0xff, 0x00, 0xc8, 0x00, 0xb4, 
  0x00, 0xc8, 0x00, 0xac, 0x00, 0xc8, 0x00, 0xff, 0x00, 0xc8, 0x00, 0xff, 0x00, 0xc8, 0x00, 0xff, 0x00, 0xc8, 0x00, 0xff, 0x00, 0xc8, 0x00, 0xff, 0x00, 0xc8, 0x00, 0xff, 0xc3, 0xe9, 0xc3, 0xff, 0xe7, 0xf6, 0xe7, 0xff, 0x00, 0xc8, 0x00, 0xff, 0x00, 0xc8, 0x00, 0xff, 0x00, 0xc8, 0x00, 0xff, 0x00, 0xc8, 0x00, 0xff, 0x00, 0xc8, 0x00, 0xff, 0x00, 0xc8, 0x00, 0xff, 0x00, 0xc8, 0x00, 0x74, 
  0x00, 0xc8, 0x00, 0x48, 0x00, 0xc8, 0x00, 0xff, 0x00, 0xc8, 0x00, 0xff, 0x00, 0xc8, 0x00, 0xff, 0x00, 0xc8, 0x00, 0xff, 0x27, 0xcd, 0x27, 0xff, 0x2a, 0xce, 0x2a, 0xff, 0xc5, 0xeb, 0xc5, 0xff, 0xe8, 0xf7, 0xe8, 0xff, 0x29, 0xce, 0x29, 0xff, 0x2a, 0xce, 0x2a, 0xff, 0x0a, 0xc9, 0x0a, 0xff, 0x00, 0xc8, 0x00, 0xff, 0x00, 0xc8, 0x00, 0xff, 0x00, 0xc8, 0x00, 0xf7, 0x00, 0xc8, 0x00, 0x18, 
  0x00, 0xce, 0x00, 0x00, 0x00, 0xc8, 0x00, 0xb3, 0x00, 0xc8, 0x00, 0xff, 0x00, 0xc8, 0x00, 0xff, 0x00, 0xc7, 0x00, 0xff, 0xf2, 0xfc, 0xf2, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x61, 0xd2, 0x61, 0xff, 0x00, 0xc8, 0x00, 0xff, 0x00, 0xc8, 0x00, 0xff, 0x00, 0xc8, 0x00, 0x77, 0x00, 0xcb, 0x00, 0x00, 
  0x00, 0x20, 0x00, 0x00, 0x00, 0xc8, 0x00, 0x10, 0x00, 0xc8, 0x00, 0xd3, 0x00, 0xc8, 0x00, 0xff, 0x00, 0xc8, 0x00, 0xff, 0x2f, 0xcc, 0x2f, 0xff, 0x33, 0xcc, 0x33, 0xff, 0x33, 0xcc, 0x33, 0xff, 0x33, 0xcc, 0x33, 0xff, 0x33, 0xcc, 0x33, 0xff, 0x33, 0xcc, 0x33, 0xff, 0x0d, 0xc9, 0x0d, 0xff, 0x00, 0xc8, 0x00, 0xff, 0x00, 0xc8, 0x00, 0xa7, 0x00, 0xc9, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0xc7, 0x00, 0x00, 0x00, 0xc9, 0x00, 0x0f, 0x00, 0xc8, 0x00, 0xac, 0x00, 0xc8, 0x00, 0xff, 0x00, 0xc8, 0x00, 0xff, 0x00, 0xc8, 0x00, 0xff, 0x00, 0xc8, 0x00, 0xff, 0x00, 0xc8, 0x00, 0xff, 0x00, 0xc8, 0x00, 0xff, 0x00, 0xc8, 0x00, 0xff, 0x00, 0xc8, 0x00, 0xfb, 0x00, 0xc8, 0x00, 0x80, 0x00, 0xc8, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xcc, 0x00, 0x00, 0x00, 0xc8, 0x00, 0x3c, 0x00, 0xc8, 0x00, 0x9c, 0x00, 0xc8, 0x00, 0xdb, 0x00, 0xc8, 0x00, 0xfb, 0x00, 0xc8, 0x00, 0xf7, 0x00, 0xc8, 0x00, 0xcf, 0x00, 0xc8, 0x00, 0x8b, 0x00, 0xc8, 0x00, 0x24, 0x00, 0xca, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
#endif
};

const lv_img_dsc_t info_1_16px = {
  .header.always_zero = 0,
  .header.w = 16,
  .header.h = 16,
  .data_size = 256 * LV_IMG_PX_SIZE_ALPHA_BYTE,
  .header.cf = LV_IMG_CF_TRUE_COLOR_ALPHA,
  .data = info_1_16px_map,
};

