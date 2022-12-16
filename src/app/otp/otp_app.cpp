#include "config.h"

#include "otp_app.h"
#include "otp_app_main.h"

#include "gui/mainbar/mainbar.h"
#include "gui/statusbar.h"
#include "gui/app.h"
#include "gui/widget.h"

uint32_t otp_app_main_tile_num;

// app icon
icon_t *otp_app = NULL;

// declare you images or fonts you need
LV_IMG_DECLARE(otp_app_64px);

/*
 * setup routine for example app
 */
void otp_app_setup( void ) {
    otp_app_main_tile_num = mainbar_add_app_tile( 1, 1, "OTP app" );
    otp_app = app_register( "OTP", &otp_app_64px, enter_otp_app_event_cb );
    otp_app_main_setup(otp_app_main_tile_num );
}

/*
 *
 */
uint32_t otp_app_get_app_main_tile_num( void ) {
    return( otp_app_main_tile_num );
}

/*
 *
 */
void enter_otp_app_event_cb( lv_obj_t * obj, lv_event_t event ) {
    switch( event ) {
        case( LV_EVENT_CLICKED ):       mainbar_jump_to_tilenumber( otp_app_main_tile_num, LV_ANIM_OFF, true );
                                        app_hide_indicator( otp_app );
                                        break;
    }
}

/*
 *
 */
void exit_otp_app_main_event_cb( lv_obj_t * obj, lv_event_t event ) {
    switch( event ) {
        case( LV_EVENT_CLICKED ):       mainbar_jump_back();
                                        break;
    }
}