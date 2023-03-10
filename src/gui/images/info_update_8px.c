#include "lvgl.h"

#ifndef LV_ATTRIBUTE_MEM_ALIGN
#define LV_ATTRIBUTE_MEM_ALIGN
#endif

#ifndef LV_ATTRIBUTE_IMG_INFO_UPDATE_8PX
#define LV_ATTRIBUTE_IMG_INFO_UPDATE_8PX
#endif

const LV_ATTRIBUTE_MEM_ALIGN LV_ATTRIBUTE_IMG_INFO_UPDATE_8PX uint8_t info_update_8px_map[] = {
#if LV_COLOR_DEPTH == 1 || LV_COLOR_DEPTH == 8
  /*Pixel format: Alpha 8 bit, Red: 3 bit, Green: 3 bit, Blue: 2 bit*/
  0x0a, 0x00, 0x13, 0x2f, 0x13, 0xb7, 0x13, 0xf4, 0x13, 0xf0, 0x13, 0xab, 0x13, 0x20, 0x00, 0x00, 
  0x13, 0x30, 0x13, 0xf4, 0x13, 0xff, 0x13, 0xff, 0x13, 0xff, 0x13, 0xff, 0x13, 0xe8, 0x13, 0x1f, 
  0x13, 0xbb, 0x13, 0xff, 0x13, 0xff, 0x13, 0xff, 0x13, 0xff, 0x13, 0xff, 0x13, 0xff, 0x13, 0xa0, 
  0x13, 0xfb, 0x13, 0xff, 0x13, 0xff, 0x13, 0xff, 0x13, 0xff, 0x13, 0xff, 0x13, 0xff, 0x13, 0xe0, 
  0x13, 0xfb, 0x13, 0xff, 0x13, 0xff, 0x13, 0xff, 0x13, 0xff, 0x13, 0xff, 0x13, 0xff, 0x13, 0xe0, 
  0x13, 0xbb, 0x13, 0xff, 0x13, 0xff, 0x13, 0xff, 0x13, 0xff, 0x13, 0xff, 0x13, 0xff, 0x13, 0xa0, 
  0x13, 0x30, 0x13, 0xf3, 0x13, 0xff, 0x13, 0xff, 0x13, 0xff, 0x13, 0xff, 0x13, 0xe8, 0x13, 0x1f, 
  0x0a, 0x00, 0x13, 0x2f, 0x13, 0xb4, 0x13, 0xf4, 0x13, 0xf0, 0x13, 0xab, 0x13, 0x20, 0x00, 0x00, 
#endif
#if LV_COLOR_DEPTH == 16 && LV_COLOR_16_SWAP == 0
  /*Pixel format: Alpha 8 bit, Red: 5 bit, Green: 6 bit, Blue: 5 bit*/
  0x11, 0x02, 0x00, 0x1f, 0x04, 0x2f, 0x1f, 0x04, 0xb7, 0x1f, 0x04, 0xf4, 0x1f, 0x04, 0xf0, 0x1f, 0x04, 0xab, 0x1f, 0x04, 0x20, 0x00, 0x00, 0x00, 
  0x1f, 0x04, 0x30, 0x1f, 0x04, 0xf4, 0x1f, 0x04, 0xff, 0x1f, 0x04, 0xff, 0x1f, 0x04, 0xff, 0x1f, 0x04, 0xff, 0x1f, 0x04, 0xe8, 0x1f, 0x04, 0x1f, 
  0x1f, 0x04, 0xbb, 0x1f, 0x04, 0xff, 0x1f, 0x04, 0xff, 0x1f, 0x04, 0xff, 0x1f, 0x04, 0xff, 0x1f, 0x04, 0xff, 0x1f, 0x04, 0xff, 0x1f, 0x04, 0xa0, 
  0x1f, 0x04, 0xfb, 0x1f, 0x04, 0xff, 0x1f, 0x04, 0xff, 0x1f, 0x04, 0xff, 0x1f, 0x04, 0xff, 0x1f, 0x04, 0xff, 0x1f, 0x04, 0xff, 0x1f, 0x04, 0xe0, 
  0x1f, 0x04, 0xfb, 0x1f, 0x04, 0xff, 0x1f, 0x04, 0xff, 0x1f, 0x04, 0xff, 0x1f, 0x04, 0xff, 0x1f, 0x04, 0xff, 0x1f, 0x04, 0xff, 0x1f, 0x04, 0xe0, 
  0x1f, 0x04, 0xbb, 0x1f, 0x04, 0xff, 0x1f, 0x04, 0xff, 0x1f, 0x04, 0xff, 0x1f, 0x04, 0xff, 0x1f, 0x04, 0xff, 0x1f, 0x04, 0xff, 0x1f, 0x04, 0xa0, 
  0x1f, 0x04, 0x30, 0x1f, 0x04, 0xf3, 0x1f, 0x04, 0xff, 0x1f, 0x04, 0xff, 0x1f, 0x04, 0xff, 0x1f, 0x04, 0xff, 0x1f, 0x04, 0xe8, 0x1f, 0x04, 0x1f, 
  0x11, 0x02, 0x00, 0x1f, 0x04, 0x2f, 0x1f, 0x04, 0xb4, 0x1f, 0x04, 0xf4, 0x1f, 0x04, 0xf0, 0x1f, 0x04, 0xab, 0x1f, 0x04, 0x20, 0x00, 0x00, 0x00, 
#endif
#if LV_COLOR_DEPTH == 16 && LV_COLOR_16_SWAP != 0
  /*Pixel format: Alpha 8 bit, Red: 5 bit, Green: 6 bit, Blue: 5 bit  BUT the 2  color bytes are swapped*/
  0x02, 0x11, 0x00, 0x04, 0x1f, 0x2f, 0x04, 0x1f, 0xb7, 0x04, 0x1f, 0xf4, 0x04, 0x1f, 0xf0, 0x04, 0x1f, 0xab, 0x04, 0x1f, 0x20, 0x00, 0x00, 0x00, 
  0x04, 0x1f, 0x30, 0x04, 0x1f, 0xf4, 0x04, 0x1f, 0xff, 0x04, 0x1f, 0xff, 0x04, 0x1f, 0xff, 0x04, 0x1f, 0xff, 0x04, 0x1f, 0xe8, 0x04, 0x1f, 0x1f, 
  0x04, 0x1f, 0xbb, 0x04, 0x1f, 0xff, 0x04, 0x1f, 0xff, 0x04, 0x1f, 0xff, 0x04, 0x1f, 0xff, 0x04, 0x1f, 0xff, 0x04, 0x1f, 0xff, 0x04, 0x1f, 0xa0, 
  0x04, 0x1f, 0xfb, 0x04, 0x1f, 0xff, 0x04, 0x1f, 0xff, 0x04, 0x1f, 0xff, 0x04, 0x1f, 0xff, 0x04, 0x1f, 0xff, 0x04, 0x1f, 0xff, 0x04, 0x1f, 0xe0, 
  0x04, 0x1f, 0xfb, 0x04, 0x1f, 0xff, 0x04, 0x1f, 0xff, 0x04, 0x1f, 0xff, 0x04, 0x1f, 0xff, 0x04, 0x1f, 0xff, 0x04, 0x1f, 0xff, 0x04, 0x1f, 0xe0, 
  0x04, 0x1f, 0xbb, 0x04, 0x1f, 0xff, 0x04, 0x1f, 0xff, 0x04, 0x1f, 0xff, 0x04, 0x1f, 0xff, 0x04, 0x1f, 0xff, 0x04, 0x1f, 0xff, 0x04, 0x1f, 0xa0, 
  0x04, 0x1f, 0x30, 0x04, 0x1f, 0xf3, 0x04, 0x1f, 0xff, 0x04, 0x1f, 0xff, 0x04, 0x1f, 0xff, 0x04, 0x1f, 0xff, 0x04, 0x1f, 0xe8, 0x04, 0x1f, 0x1f, 
  0x02, 0x11, 0x00, 0x04, 0x1f, 0x2f, 0x04, 0x1f, 0xb4, 0x04, 0x1f, 0xf4, 0x04, 0x1f, 0xf0, 0x04, 0x1f, 0xab, 0x04, 0x1f, 0x20, 0x00, 0x00, 0x00, 
#endif
#if LV_COLOR_DEPTH == 32
  0x89, 0x42, 0x00, 0x00, 0xff, 0x80, 0x00, 0x2f, 0xff, 0x80, 0x00, 0xb7, 0xff, 0x80, 0x00, 0xf4, 0xff, 0x80, 0x00, 0xf0, 0xff, 0x80, 0x00, 0xab, 0xff, 0x80, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 
  0xff, 0x80, 0x00, 0x30, 0xff, 0x80, 0x00, 0xf4, 0xff, 0x80, 0x00, 0xff, 0xff, 0x80, 0x00, 0xff, 0xff, 0x80, 0x00, 0xff, 0xff, 0x80, 0x00, 0xff, 0xff, 0x80, 0x00, 0xe8, 0xff, 0x80, 0x00, 0x1f, 
  0xff, 0x80, 0x00, 0xbb, 0xff, 0x80, 0x00, 0xff, 0xff, 0x80, 0x00, 0xff, 0xff, 0x80, 0x00, 0xff, 0xff, 0x80, 0x00, 0xff, 0xff, 0x80, 0x00, 0xff, 0xff, 0x80, 0x00, 0xff, 0xff, 0x80, 0x00, 0xa0, 
  0xff, 0x80, 0x00, 0xfb, 0xff, 0x80, 0x00, 0xff, 0xff, 0x80, 0x00, 0xff, 0xff, 0x80, 0x00, 0xff, 0xff, 0x80, 0x00, 0xff, 0xff, 0x80, 0x00, 0xff, 0xff, 0x80, 0x00, 0xff, 0xff, 0x80, 0x00, 0xe0, 
  0xff, 0x80, 0x00, 0xfb, 0xff, 0x80, 0x00, 0xff, 0xff, 0x80, 0x00, 0xff, 0xff, 0x80, 0x00, 0xff, 0xff, 0x80, 0x00, 0xff, 0xff, 0x80, 0x00, 0xff, 0xff, 0x80, 0x00, 0xff, 0xff, 0x80, 0x00, 0xe0, 
  0xff, 0x80, 0x00, 0xbb, 0xff, 0x80, 0x00, 0xff, 0xff, 0x80, 0x00, 0xff, 0xff, 0x80, 0x00, 0xff, 0xff, 0x80, 0x00, 0xff, 0xff, 0x80, 0x00, 0xff, 0xff, 0x80, 0x00, 0xff, 0xff, 0x80, 0x00, 0xa0, 
  0xff, 0x80, 0x00, 0x30, 0xff, 0x80, 0x00, 0xf3, 0xff, 0x80, 0x00, 0xff, 0xff, 0x80, 0x00, 0xff, 0xff, 0x80, 0x00, 0xff, 0xff, 0x80, 0x00, 0xff, 0xff, 0x80, 0x00, 0xe8, 0xff, 0x80, 0x00, 0x1f, 
  0x89, 0x42, 0x00, 0x00, 0xff, 0x80, 0x00, 0x2f, 0xff, 0x80, 0x00, 0xb4, 0xff, 0x80, 0x00, 0xf4, 0xff, 0x80, 0x00, 0xf0, 0xff, 0x80, 0x00, 0xab, 0xff, 0x80, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 
#endif
};

const lv_img_dsc_t info_update_8px = {
  .header.always_zero = 0,
  .header.w = 8,
  .header.h = 8,
  .data_size = 64 * LV_IMG_PX_SIZE_ALPHA_BYTE,
  .header.cf = LV_IMG_CF_TRUE_COLOR_ALPHA,
  .data = info_update_8px_map,
};

