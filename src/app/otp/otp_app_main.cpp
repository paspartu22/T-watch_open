#include "config.h"

#include <stdio.h>
#include <stdlib.h>
#include "otp_app.h"
#include "otp_app_main.h"

//#include "lv_color.h"

#include "SimpleHOTP/SimpleHOTP.h"
#include "hardware/timesync.h"

#include "gui/mainbar/app_tile/app_tile.h"
#include "gui/mainbar/main_tile/main_tile.h"
#include "gui/mainbar/mainbar.h"
#include "gui/statusbar.h"
#include "gui/widget_factory.h"
#include "gui/widget_styles.h"



lv_obj_t *otp_app_main_tile = NULL;
lv_obj_t *lvgl_otp; 
lv_obj_t *timer;
lv_obj_t *bar;
lv_task_t *update;
 
char secret[] = "82A9D42DCE0236BD01EA1CCBFBBD54B7454FF431"; //TOTP key
const int hotp_lenght = 6;    //from 6 to 9 digits
char char_otp[hotp_lenght+1];   //+'\0'
uint32_t otp = 0;
Key key(secret, sizeof(secret)-1);
SimpleHOTP gen(key, 0);


bool otp_mainbar_button_event_cb( EventBits_t event, void *arg );
int last_time_sync = 0;
int bar_width = 0;

void my_task(lv_task_t * task)
{
    time_t now = time(NULL);
    uint32_t T0 = 946684800; // 00:00:00 01.01.2000 946684800
    uint8_t X = 30; // sec for OTP
    uint32_t T = ((intmax_t)now - T0)/X;

    gen.generateStrHOTP(T, char_otp);
    lv_label_set_text(lvgl_otp, char_otp);
    lv_obj_align(lvgl_otp, NULL, LV_ALIGN_CENTER, 0, 0);

    char buffer[3];
    sprintf (buffer, "%llu", 30-((intmax_t)now - T0)%X);
    lv_label_set_text(timer, buffer);
    lv_obj_align(timer, NULL, LV_ALIGN_IN_BOTTOM_MID, 0, -20);


    int bar_width = 100 - ((intmax_t)now - T0) % X * 100 / X;
  
    lv_bar_set_value(bar, bar_width, LV_ANIM_ON);
    //lv_example_bar_2();
}

void otp_app_main_setup ( uint32_t tile_num){

    otp_app_main_tile = mainbar_get_tile_obj( tile_num );

    lv_obj_t *exit_btn = wf_add_exit_button( otp_app_main_tile, exit_otp_app_main_event_cb );
    lv_obj_align(exit_btn, otp_app_main_tile, LV_ALIGN_IN_BOTTOM_LEFT, THEME_ICON_PADDING, -THEME_ICON_PADDING );

    static lv_style_t style1;
    lv_style_init(&style1);
    lv_style_copy(&style1, ws_get_label_style());
    lv_style_set_text_color(&style1, LV_STATE_DEFAULT, LV_COLOR_WHITE);
    lv_style_set_text_font(&style1, LV_STATE_DEFAULT, &lv_font_montserrat_48);
    lvgl_otp = lv_label_create(otp_app_main_tile, NULL);
    lv_obj_add_style(lvgl_otp, LV_OBJ_PART_MAIN, &style1); 
    timer = lv_label_create(otp_app_main_tile, NULL);  
    lv_obj_add_style(timer, LV_OBJ_PART_MAIN, &style1);

    static lv_style_t style_bg;
    static lv_style_t style_indic;

    lv_style_init(&style_bg);
    lv_style_set_border_color(&style_bg, LV_STATE_DEFAULT, LV_COLOR_WHITE);
    lv_style_set_border_width(&style_bg, LV_STATE_DEFAULT, 2);
    lv_style_set_pad_all(&style_bg, LV_STATE_DEFAULT, 6); //To make the indicator smaller
    lv_style_set_radius(&style_bg, LV_STATE_DEFAULT, 6);

    lv_style_init(&style_indic);
    lv_style_set_bg_opa(&style_indic, LV_STATE_DEFAULT, LV_OPA_COVER);
    lv_style_set_bg_color(&style_indic, LV_STATE_DEFAULT, LV_COLOR_WHITE);
    lv_style_set_radius(&style_indic, LV_STATE_DEFAULT, 3);

    bar = lv_bar_create(otp_app_main_tile, NULL);
    lv_obj_add_style(bar, LV_BAR_PART_BG, &style_bg);
    lv_obj_add_style(bar, LV_BAR_PART_INDIC, &style_indic);
    lv_obj_set_size(bar, 200, 30);
    lv_obj_align(bar, NULL, LV_ALIGN_IN_TOP_MID, 0, 40);

    mainbar_add_tile_button_cb(tile_num, otp_mainbar_button_event_cb );
    update = lv_task_create(my_task, 2000, LV_TASK_PRIO_LOW, NULL);
}

bool otp_mainbar_button_event_cb( EventBits_t event, void *arg ) {
    switch( event ) {
        case BUTTON_EXIT:   mainbar_jump_back();
                            break;
    }
    return( true );
}

void focus_otp(){
    lv_task_set_period(update, 100);
}

void unfocus_otp(){
    lv_task_set_period(update, -1);
}
