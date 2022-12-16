

#include "config.h"
#include <stdio.h>
#include <stdlib.h>
#include "otp_app.h"
#include "otp_app_main.h"

#include "SimpleHOTP/SimpleHOTP.h"


#include "gui/mainbar/app_tile/app_tile.h"
#include "gui/mainbar/main_tile/main_tile.h"
#include "gui/mainbar/mainbar.h"
#include "gui/statusbar.h"
#include "gui/widget_factory.h"
#include "gui/widget_styles.h"

lv_obj_t *otp_app_main_tile = NULL;

char secret[] = "92A9D42DCE0236BD01EA1CCBFBBD54B7454FF421";
const int hotp_lenght = 6;    //from 6 to 9 digits
char char_otp[hotp_lenght+1];   //+'\0'
uint32_t otp = 0;
Key key(secret, sizeof(secret)-1);
SimpleHOTP gen(key, 0);


lv_obj_t *lvgl_otp;  

void otp_app_main_setup ( uint32_t tile_num ){
    otp_app_main_tile = mainbar_get_tile_obj( tile_num );

        lv_obj_t * exit_btn = wf_add_exit_button( otp_app_main_tile, exit_otp_app_main_event_cb );
    #if defined( ROUND_DISPLAY )
        lv_obj_align(exit_btn, otp_app_main_tile, LV_ALIGN_IN_BOTTOM_MID, -( THEME_ICON_SIZE / 2 ), -THEME_ICON_PADDING );
    #else
        lv_obj_align(exit_btn, otp_app_main_tile, LV_ALIGN_IN_BOTTOM_LEFT, THEME_ICON_PADDING, -THEME_ICON_PADDING );
    #endif
    

    static lv_style_t style1;
    lv_style_init(&style1);
    lv_style_set_text_color(&style1, LV_STATE_DEFAULT, LV_COLOR_BLACK);
    lv_style_set_text_font(&style1, LV_STATE_DEFAULT, &lv_font_montserrat_44);

    lvgl_otp = lv_label_create(lv_scr_act(), NULL);
    lv_obj_add_style(lvgl_otp, LV_OBJ_PART_MAIN, &style1);   
    
    gen.generateStrHOTP(char_otp);
    gen.saveCounter();
    lv_label_set_text(lvgl_otp, char_otp);
    lv_obj_align(lvgl_otp, NULL, LV_ALIGN_CENTER, 0, 0);

    lv_obj_align(lvgl_otp, NULL, LV_ALIGN_CENTER, 0, 0);
    
    //mainbar_add_tile_button_cb( tile_num, otp_mainbar_button_event_cb );
}
/*
void otp_app_main_setup( uint32_t tile_num ) {
    
    Change the active screen's background color*/
   

    /*Create a white label, set its text and align it to the center*/
    /*
    lv_obj_t * label = lv_label_create(lv_scr_act());
    gen.generateStrHOTP(char_otp);
    gen.saveCounter();
    lv_label_set_text(label, char_otp);
    //lv_obj_set_style_text_color(lv_scr_act(), lv_color_hex(0xffffff), LV_PART_MAIN);
    lv_obj_align(label, LV_ALIGN_CENTER, 0, 0);
    
    otp_app_main_tile = mainbar_get_tile_obj( tile_num );

    lv_obj_t * exit_btn = wf_add_exit_button( calc_app_main_tile, exit_calc_app_main_event_cb );
    #if defined( ROUND_DISPLAY )
        lv_obj_align(exit_btn, calc_app_main_tile, LV_ALIGN_IN_BOTTOM_MID, -( THEME_ICON_SIZE / 2 ), -THEME_ICON_PADDING );
    #else
        lv_obj_align(exit_btn, calc_app_main_tile, LV_ALIGN_IN_BOTTOM_LEFT, THEME_ICON_PADDING, -THEME_ICON_PADDING );
    #endif

    lv_obj_t * otp = result_label = lv_label_create( calc_app_main_tile, "OTP");

    lv_obj_t * result_btn = wf_add_equal_button( calc_app_main_tile, calc_result_event_cb );
    #if defined( ROUND_DISPLAY )
        lv_obj_align(result_btn, calc_app_main_tile, LV_ALIGN_IN_BOTTOM_MID, THEME_ICON_SIZE / 2, -THEME_ICON_PADDING );
    #else
        lv_obj_align(result_btn, calc_app_main_tile, LV_ALIGN_IN_BOTTOM_RIGHT, -THEME_ICON_PADDING, -THEME_ICON_PADDING );
    #endif

    // result label
    lv_style_copy(&result_style, ws_get_label_style());
    lv_style_set_text_color(&result_style, LV_STATE_DEFAULT, LV_COLOR_BLACK);
    lv_style_set_bg_color(&result_style, LV_STATE_DEFAULT, LV_COLOR_WHITE);
    lv_style_set_bg_opa(&result_style, LV_STATE_DEFAULT, LV_OPA_80);
    lv_style_set_text_font(&result_style, LV_STATE_DEFAULT, &Ubuntu_32px);
	lv_style_set_pad_top(&result_style, LV_STATE_DEFAULT, 10);
	lv_style_set_pad_left(&result_style, LV_STATE_DEFAULT, 3);
	lv_style_set_pad_right(&result_style, LV_STATE_DEFAULT, 3);

    result_label = lv_label_create( calc_app_main_tile, NULL);
    lv_label_set_text(result_label, "0");
    #if defined( ROUND_DISPLAY )
        lv_label_set_align(result_label, LV_LABEL_ALIGN_CENTER );
	#else
        lv_label_set_align(result_label, LV_LABEL_ALIGN_RIGHT );
    #endif
    lv_label_set_long_mode(result_label, LV_LABEL_LONG_CROP);
    lv_obj_add_style(result_label, LV_OBJ_PART_MAIN, &result_style);
    lv_obj_align(result_label, calc_app_main_tile, LV_ALIGN_IN_TOP_LEFT, 0, 0 );
	lv_obj_set_size(result_label, lv_disp_get_hor_res( NULL ), 45 );

    // history label
    lv_style_copy(&history_style, ws_get_label_style());
    lv_style_set_text_color(&history_style, LV_STATE_DEFAULT, LV_COLOR_BLACK);
    lv_style_set_bg_color(&history_style, LV_STATE_DEFAULT, LV_COLOR_WHITE);
    lv_style_set_bg_opa(&history_style, LV_STATE_DEFAULT, LV_OPA_TRANSP);
    lv_style_set_text_opa(&history_style, LV_STATE_DEFAULT, LV_OPA_50);
    lv_style_set_text_font(&history_style, LV_STATE_DEFAULT, &Ubuntu_12px);
	lv_style_set_pad_left(&history_style, LV_STATE_DEFAULT, 3);
	lv_style_set_pad_right(&history_style, LV_STATE_DEFAULT, 3);

    history_label = lv_label_create( calc_app_main_tile, NULL);
    lv_label_set_text(history_label, "");
    #if defined( ROUND_DISPLAY )
        lv_label_set_align(history_label, LV_LABEL_ALIGN_CENTER );
	#else
        lv_label_set_align(history_label, LV_LABEL_ALIGN_RIGHT );
    #endif
    lv_label_set_long_mode(history_label, LV_LABEL_LONG_CROP);
    lv_obj_add_style(history_label, LV_OBJ_PART_MAIN, &history_style);
    lv_obj_align(history_label, calc_app_main_tile, LV_ALIGN_IN_TOP_LEFT, 0, -2 );
	lv_obj_set_size(history_label, lv_disp_get_hor_res( NULL ), 15 );
    
    button_matrix = lv_btnmatrix_create(calc_app_main_tile, NULL);
	lv_obj_add_style(button_matrix, LV_BTNMATRIX_PART_BG, APP_STYLE );
	lv_obj_add_style(button_matrix, LV_BTNMATRIX_PART_BTN, ws_get_button_style() );
    lv_obj_set_style_local_bg_opa( button_matrix, LV_BTNMATRIX_PART_BTN, LV_STATE_DEFAULT, LV_OPA_80 );
	lv_obj_set_pos( button_matrix, 0, 45);
	lv_obj_set_size(button_matrix, lv_disp_get_hor_res( NULL ), lv_disp_get_ver_res( NULL ) - 38 - THEME_ICON_SIZE );

	lv_btnmatrix_set_map(button_matrix, buttons);
	lv_btnmatrix_set_one_check(button_matrix, false);
    lv_btnmatrix_set_btn_ctrl(button_matrix, 3, LV_BTNMATRIX_CTRL_CHECKABLE);
    lv_btnmatrix_set_btn_ctrl(button_matrix, 7, LV_BTNMATRIX_CTRL_CHECKABLE);
    lv_btnmatrix_set_btn_ctrl(button_matrix, 11, LV_BTNMATRIX_CTRL_CHECKABLE);
    lv_btnmatrix_set_btn_ctrl(button_matrix, 15, LV_BTNMATRIX_CTRL_CHECKABLE);
    lv_obj_set_event_cb(button_matrix, calc_button_event_cb);

    mainbar_add_tile_button_cb( tile_num, calc_mainbar_button_event_cb );
  
}
*/
