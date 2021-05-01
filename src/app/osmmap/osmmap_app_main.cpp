/****************************************************************************
 *   Aug 3 12:17:11 2020
 *   Copyright  2020  Dirk Brosswick
 *   Email: dirk.brosswick@googlemail.com
 ****************************************************************************/
 
/*
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */
#include "config.h"
#include <TTGO.h>
#include "quickglui/quickglui.h"

#include "osmmap_app.h"
#include "osmmap_app_main.h"
#include "app/osmmap/config/osmmap_config.h"

#include "gui/mainbar/setup_tile/bluetooth_settings/bluetooth_message.h"
#include "gui/mainbar/app_tile/app_tile.h"
#include "gui/mainbar/main_tile/main_tile.h"
#include "gui/mainbar/mainbar.h"
#include "gui/statusbar.h"
#include "gui/widget_styles.h"

#include "hardware/display.h"
#include "hardware/gpsctl.h"
#include "hardware/blectl.h"
#include "hardware/wifictl.h"
#include "hardware/touch.h"

#include "utils/osm_map/osm_map.h"
#include "utils/json_psram_allocator.h"

extern const uint8_t osm_server_json_start[] asm("_binary_src_utils_osm_map_osmtileserver_json_start");
extern const uint8_t osm_server_json_end[] asm("_binary_src_utils_osm_map_osmtileserver_json_end");

EventGroupHandle_t osmmap_event_handle = NULL;     /** @brief osm tile image update event queue */
TaskHandle_t _osmmap_download_Task;                /** @brief osm tile image update Task */
lv_task_t *osmmap_main_tile_task;                  /** @brief osm active/inactive task for show/hide user interface */

lv_obj_t *osmmap_app_main_tile = NULL;              /** @brief osm main tile obj */
lv_obj_t *osmmap_app_tile_img = NULL;               /** @brief osm tile image obj */
lv_obj_t *osmmap_app_pos_img = NULL;                /** @brief osm position point obj */
lv_obj_t *osmmap_lonlat_label = NULL;               /** @brief osm exit icon/button obj */
lv_obj_t *north_btn = NULL;                          /** @brief osm exit icon/button obj */
lv_obj_t *south_btn = NULL;                          /** @brief osm exit icon/button obj */
lv_obj_t *west_btn = NULL;                          /** @brief osm exit icon/button obj */
lv_obj_t *zoom_northwest_btn = NULL;                          /** @brief osm exit icon/button obj */
lv_obj_t *zoom_northeast_btn = NULL;                          /** @brief osm exit icon/button obj */
lv_obj_t *zoom_southwest_btn = NULL;                          /** @brief osm exit icon/button obj */
lv_obj_t *zoom_southeast_btn = NULL;                          /** @brief osm exit icon/button obj */
lv_obj_t *east_btn = NULL;                          /** @brief osm exit icon/button obj */
lv_obj_t *exit_btn = NULL;                          /** @brief osm exit icon/button obj */
lv_obj_t *zoom_in_btn = NULL;                       /** @brief osm zoom in icon/button obj */
lv_obj_t *zoom_out_btn = NULL;                      /** @brief osm zoom out icon/button obj */

lv_obj_t *layers_btn = NULL;                          /** @brief osm exit icon/button obj */
lv_obj_t *top_menu = NULL;
lv_obj_t *sub_menu_layers = NULL;
lv_obj_t *sub_menu_setting = NULL;                       /** @brief osm style list box */

lv_style_t osmmap_app_main_style;                   /** @brief osm main styte obj */
lv_style_t osmmap_app_label_style;                  /** @brief osm main styte obj */
lv_style_t osmmap_app_nav_style;                  /** @brief osm main styte obj */

static bool osmmap_app_active = false;              /** @brief osm app active/inactive flag, true means active */
static bool osmmap_block_return_maintile = false;   /** @brief osm block to maintile state store */
static bool osmmap_block_show_messages = false;     /** @brief osm show messages state store */
static bool osmmap_statusbar_force_dark_mode = false;  /** @brief osm statusbar force dark mode state store */
static bool osmmap_gps_state = false;
static bool osmmap_wifi_state = false;
static uint64_t last_touch = 0;
osm_location_t *osmmap_location = NULL;             /** @brief osm location obj */
osmmap_config_t osmmap_config;

LV_IMG_DECLARE(layers_dark_48px);
LV_IMG_DECLARE(exit_dark_48px);
LV_IMG_DECLARE(zoom_in_dark_48px);
LV_IMG_DECLARE(zoom_out_dark_48px);
LV_IMG_DECLARE(osm_64px);
LV_IMG_DECLARE(info_fail_16px);
LV_IMG_DECLARE(checked_dark_16px);
LV_IMG_DECLARE(unchecked_dark_16px);
LV_FONT_DECLARE(Ubuntu_12px);
LV_FONT_DECLARE(Ubuntu_16px);
LV_FONT_DECLARE(Ubuntu_32px);

void osmmap_main_tile_update_task( lv_task_t * task );
void osmmap_update_request( void );
void osmmap_update_Task( void * pvParameters );
static void osmmap_app_get_setting_menu_cb( lv_obj_t * obj, lv_event_t event );
void osmmap_app_set_setting_menu( lv_obj_t *menu );
bool osmmap_app_touch_event_cb( EventBits_t event, void *arg );
static void nav_direction_osmmap_app_main_event_cb( lv_obj_t * obj, lv_event_t event );
static void nav_center_osmmap_app_main_event_cb( lv_obj_t * obj, lv_event_t event );
static void zoom_in_osmmap_app_main_event_cb( lv_obj_t * obj, lv_event_t event );
static void zoom_out_osmmap_app_main_event_cb( lv_obj_t * obj, lv_event_t event );
static void exit_osmmap_app_main_event_cb( lv_obj_t * obj, lv_event_t event );
static void osmmap_tile_server_event_cb( lv_obj_t * obj, lv_event_t event );
static void layers_btn_app_main_event_cb( lv_obj_t * obj, lv_event_t event );
void osmmap_update_map( osm_location_t *osmmap_location, double lon, double lat, uint32_t zoom );
bool osmmap_gpsctl_event_cb( EventBits_t event, void *arg );
void osmmap_add_tile_server_list( lv_obj_t *layers_list );
void osmmap_activate_cb( void );
void osmmap_hibernate_cb( void );

void osmmap_app_main_setup( uint32_t tile_num ) {
    /**
     * load config
     */
    osmmap_config.load();
    osmmap_location = osm_map_create_location_obj();
    osmmap_location->load_ahead = osmmap_config.load_ahead;
    /**
     * geht app tile
     */
    osmmap_app_main_tile = mainbar_get_tile_obj( tile_num );

    lv_style_copy( &osmmap_app_main_style, ws_get_mainbar_style() );
    lv_obj_add_style( osmmap_app_main_tile, LV_OBJ_PART_MAIN, &osmmap_app_main_style );

    lv_style_copy( &osmmap_app_nav_style, ws_get_mainbar_style() );
    lv_style_set_radius( &osmmap_app_nav_style, LV_OBJ_PART_MAIN, 0 );
    lv_style_set_bg_color( &osmmap_app_nav_style, LV_OBJ_PART_MAIN, LV_COLOR_BLACK );

    lv_style_copy( &osmmap_app_label_style, ws_get_mainbar_style() );
    lv_style_set_text_font( &osmmap_app_label_style, LV_OBJ_PART_MAIN, &Ubuntu_12px );
    lv_style_set_text_color(&osmmap_app_label_style, LV_OBJ_PART_MAIN, LV_COLOR_BLACK );

    lv_obj_t *osmmap_cont = lv_obj_create( osmmap_app_main_tile, NULL );
    lv_obj_set_size(osmmap_cont, lv_disp_get_hor_res( NULL ), lv_disp_get_ver_res( NULL ) );
    lv_obj_add_style( osmmap_cont, LV_OBJ_PART_MAIN, &osmmap_app_main_style );
    lv_obj_align( osmmap_cont, osmmap_app_main_tile, LV_ALIGN_IN_TOP_RIGHT, 0, 0 );

    osmmap_app_tile_img = lv_img_create( osmmap_cont, NULL );
    lv_obj_set_width( osmmap_app_tile_img, lv_disp_get_hor_res( NULL ) );
    lv_obj_set_height( osmmap_app_tile_img, lv_disp_get_ver_res( NULL ) );
    lv_img_set_src( osmmap_app_tile_img, osm_map_get_no_data_image() );
    lv_obj_align( osmmap_app_tile_img, osmmap_cont, LV_ALIGN_CENTER, 0, 0 );

    osmmap_app_pos_img = lv_img_create( osmmap_cont, NULL );
    lv_img_set_src( osmmap_app_pos_img, &info_fail_16px );
    lv_obj_align( osmmap_app_pos_img, osmmap_cont, LV_ALIGN_IN_TOP_LEFT, 120, 120 );
    lv_obj_set_hidden( osmmap_app_pos_img, true );

    osmmap_lonlat_label = lv_label_create( osmmap_cont, NULL );
    lv_obj_add_style( osmmap_lonlat_label, LV_OBJ_PART_MAIN, &osmmap_app_label_style );
    lv_obj_align( osmmap_lonlat_label, osmmap_cont, LV_ALIGN_IN_TOP_LEFT, 3, 0 );
    lv_label_set_text( osmmap_lonlat_label, "0 / 0" );

    layers_btn = lv_imgbtn_create( osmmap_cont, NULL);
    lv_imgbtn_set_src( layers_btn, LV_BTN_STATE_RELEASED, &layers_dark_48px);
    lv_imgbtn_set_src( layers_btn, LV_BTN_STATE_PRESSED, &layers_dark_48px);
    lv_imgbtn_set_src( layers_btn, LV_BTN_STATE_CHECKED_RELEASED, &layers_dark_48px);
    lv_imgbtn_set_src( layers_btn, LV_BTN_STATE_CHECKED_PRESSED, &layers_dark_48px);
    lv_obj_add_style( layers_btn, LV_IMGBTN_PART_MAIN, &osmmap_app_main_style );
    lv_obj_align( layers_btn, osmmap_cont, LV_ALIGN_IN_TOP_LEFT, 10, 10 );
    lv_obj_set_event_cb( layers_btn, layers_btn_app_main_event_cb );

    exit_btn = lv_imgbtn_create( osmmap_cont, NULL);
    lv_imgbtn_set_src( exit_btn, LV_BTN_STATE_RELEASED, &exit_dark_48px);
    lv_imgbtn_set_src( exit_btn, LV_BTN_STATE_PRESSED, &exit_dark_48px);
    lv_imgbtn_set_src( exit_btn, LV_BTN_STATE_CHECKED_RELEASED, &exit_dark_48px);
    lv_imgbtn_set_src( exit_btn, LV_BTN_STATE_CHECKED_PRESSED, &exit_dark_48px);
    lv_obj_add_style( exit_btn, LV_IMGBTN_PART_MAIN, &osmmap_app_main_style );
    lv_obj_align( exit_btn, osmmap_cont, LV_ALIGN_IN_BOTTOM_LEFT, 10, -10 );
    lv_obj_set_event_cb( exit_btn, exit_osmmap_app_main_event_cb );

    zoom_in_btn = lv_imgbtn_create( osmmap_cont, NULL);
    lv_imgbtn_set_src( zoom_in_btn, LV_BTN_STATE_RELEASED, &zoom_in_dark_48px);
    lv_imgbtn_set_src( zoom_in_btn, LV_BTN_STATE_PRESSED, &zoom_in_dark_48px);
    lv_imgbtn_set_src( zoom_in_btn, LV_BTN_STATE_CHECKED_RELEASED, &zoom_in_dark_48px);
    lv_imgbtn_set_src( zoom_in_btn, LV_BTN_STATE_CHECKED_PRESSED, &zoom_in_dark_48px);
    lv_obj_add_style( zoom_in_btn, LV_IMGBTN_PART_MAIN, &osmmap_app_main_style );
    lv_obj_align( zoom_in_btn, osmmap_cont, LV_ALIGN_IN_TOP_RIGHT, -10, 10 );
    lv_obj_set_event_cb( zoom_in_btn, zoom_in_osmmap_app_main_event_cb );

    zoom_out_btn = lv_imgbtn_create( osmmap_cont, NULL);
    lv_imgbtn_set_src( zoom_out_btn, LV_BTN_STATE_RELEASED, &zoom_out_dark_48px);
    lv_imgbtn_set_src( zoom_out_btn, LV_BTN_STATE_PRESSED, &zoom_out_dark_48px);
    lv_imgbtn_set_src( zoom_out_btn, LV_BTN_STATE_CHECKED_RELEASED, &zoom_out_dark_48px);
    lv_imgbtn_set_src( zoom_out_btn, LV_BTN_STATE_CHECKED_PRESSED, &zoom_out_dark_48px);
    lv_obj_add_style( zoom_out_btn, LV_IMGBTN_PART_MAIN, &osmmap_app_main_style );
    lv_obj_align( zoom_out_btn, osmmap_cont, LV_ALIGN_IN_BOTTOM_RIGHT, -10, -10 );
    lv_obj_set_event_cb( zoom_out_btn, zoom_out_osmmap_app_main_event_cb );

    north_btn = lv_btn_create( osmmap_cont, NULL );
    lv_obj_set_width( north_btn, 80 );
    lv_obj_set_height( north_btn, 48 );
    lv_obj_add_protect( north_btn, LV_PROTECT_CLICK_FOCUS );
    lv_obj_add_style( north_btn, LV_BTN_PART_MAIN, &osmmap_app_nav_style );
    lv_obj_align( north_btn, osmmap_cont, LV_ALIGN_IN_TOP_MID, 0, 0 );
    lv_obj_set_event_cb( north_btn, nav_direction_osmmap_app_main_event_cb );

    south_btn = lv_btn_create( osmmap_cont, north_btn );
    lv_obj_align( south_btn, osmmap_cont, LV_ALIGN_IN_BOTTOM_MID, 0, 0 );
    lv_obj_set_event_cb( south_btn, nav_direction_osmmap_app_main_event_cb );

    west_btn = lv_btn_create( osmmap_cont, NULL );
    lv_obj_set_width( west_btn, 48 );
    lv_obj_set_height( west_btn, 80 );
    lv_obj_add_protect( west_btn, LV_PROTECT_CLICK_FOCUS );
    lv_obj_add_style( west_btn, LV_BTN_PART_MAIN, &osmmap_app_nav_style );
    lv_obj_align( west_btn, osmmap_cont, LV_ALIGN_IN_LEFT_MID, 0, 0 );
    lv_obj_set_event_cb( west_btn, nav_direction_osmmap_app_main_event_cb );

    east_btn = lv_btn_create( osmmap_cont, west_btn );
    lv_obj_align( east_btn, osmmap_cont, LV_ALIGN_IN_RIGHT_MID, 0, 0 );
    lv_obj_set_event_cb( east_btn, nav_direction_osmmap_app_main_event_cb );

    zoom_northwest_btn = lv_btn_create( osmmap_cont, NULL );
    lv_obj_set_width( zoom_northwest_btn, 72 );
    lv_obj_set_height( zoom_northwest_btn, 72 );
    lv_obj_add_protect( zoom_northwest_btn, LV_PROTECT_CLICK_FOCUS );
    lv_imgbtn_set_checkable( zoom_northwest_btn, true );
    lv_obj_add_style( zoom_northwest_btn, LV_BTN_PART_MAIN, &osmmap_app_nav_style );
    lv_obj_align( zoom_northwest_btn, osmmap_cont, LV_ALIGN_CENTER, -36, -36 );
    lv_obj_set_event_cb( zoom_northwest_btn, nav_center_osmmap_app_main_event_cb );

    zoom_northeast_btn = lv_btn_create( osmmap_cont, zoom_northwest_btn );
    lv_obj_align( zoom_northeast_btn, osmmap_cont, LV_ALIGN_CENTER, 36, -36 );
    lv_obj_set_event_cb( zoom_northeast_btn, nav_center_osmmap_app_main_event_cb );

    zoom_southwest_btn = lv_btn_create( osmmap_cont, zoom_northwest_btn );
    lv_obj_align( zoom_southwest_btn, osmmap_cont, LV_ALIGN_CENTER, -36, 36 );
    lv_obj_set_event_cb( zoom_southwest_btn, nav_center_osmmap_app_main_event_cb );

    zoom_southeast_btn = lv_btn_create( osmmap_cont, zoom_northwest_btn );
    lv_obj_align( zoom_southeast_btn, osmmap_cont, LV_ALIGN_CENTER, 36, 36 );
    lv_obj_set_event_cb( zoom_southeast_btn, nav_center_osmmap_app_main_event_cb );
    /**
     * setup menu
     */
    sub_menu_layers = lv_list_create( osmmap_cont, NULL );
    lv_obj_set_size( sub_menu_layers, 160, 200 );
    lv_obj_align( sub_menu_layers, NULL, LV_ALIGN_IN_RIGHT_MID, 0, 0);
    osmmap_add_tile_server_list( sub_menu_layers );
    lv_obj_set_hidden( sub_menu_layers, true );

    sub_menu_setting = lv_list_create( osmmap_cont, NULL );
    lv_obj_set_size( sub_menu_setting, 160, 200 );
    lv_obj_align( sub_menu_setting, NULL, LV_ALIGN_IN_RIGHT_MID, 0, 0);
    osmmap_app_set_setting_menu( sub_menu_setting );
    lv_obj_set_hidden( sub_menu_setting, true );
    /**
     * setup event callback and background Task
     */
    mainbar_add_tile_activate_cb( tile_num, osmmap_activate_cb );
    mainbar_add_tile_hibernate_cb( tile_num, osmmap_hibernate_cb );
    gpsctl_register_cb( GPSCTL_SET_APP_LOCATION | GPSCTL_UPDATE_LOCATION, osmmap_gpsctl_event_cb, "osm" );
    touch_register_cb( TOUCH_UPDATE , osmmap_app_touch_event_cb, "osm touch" );
    osmmap_event_handle = xEventGroupCreate();
    osmmap_main_tile_task = lv_task_create( osmmap_main_tile_update_task, 250, LV_TASK_PRIO_MID, NULL );
}

bool osmmap_app_touch_event_cb( EventBits_t event, void *arg ) {
    switch( event ) {
        case( TOUCH_UPDATE ):
            last_touch = millis();
            break;
    }
    return( true );
}

void osmmap_app_set_setting_menu( lv_obj_t *menu ) {
    lv_obj_t * menu_entry;
    char cachestring[32] = "";

    if ( menu ) {
        /**
         * clear all menu entrys
         */
        while ( lv_list_remove( menu, 0 ) );
        /**
         * add menu entry
         */
        menu_entry = lv_list_add_btn( menu, NULL, "OSM maps" );
        lv_obj_set_event_cb( menu_entry, osmmap_app_get_setting_menu_cb );
        menu_entry = lv_list_add_btn( menu, osmmap_config.gps_autoon ? &checked_dark_16px : &unchecked_dark_16px, "autostart gps" );
        lv_obj_set_event_cb( menu_entry, osmmap_app_get_setting_menu_cb );
        menu_entry = lv_list_add_btn( menu, osmmap_config.wifi_autoon ? &checked_dark_16px : &unchecked_dark_16px, "autostart wifi" );
        lv_obj_set_event_cb( menu_entry, osmmap_app_get_setting_menu_cb );
        menu_entry = lv_list_add_btn( menu, osmmap_config.load_ahead ? &checked_dark_16px : &unchecked_dark_16px, "load ahead" );
        lv_obj_set_event_cb( menu_entry, osmmap_app_get_setting_menu_cb );
        snprintf( cachestring, sizeof( cachestring ), "%dkB cached", osm_map_get_used_cache_size( osmmap_location ) / 1024 );
        menu_entry = lv_list_add_btn( menu, NULL, cachestring );
        lv_obj_set_event_cb( menu_entry, osmmap_app_get_setting_menu_cb );
    }
}

static void osmmap_app_get_setting_menu_cb( lv_obj_t * obj, lv_event_t event ) {
    switch( event ) {
        case( LV_EVENT_CLICKED ):
            if ( !strcmp( lv_list_get_btn_text( obj ), "OSM maps") ) {
                lv_obj_set_hidden( sub_menu_setting, true );
                lv_obj_set_hidden( sub_menu_layers, false );

            }
            else if ( !strcmp( lv_list_get_btn_text( obj ), "load ahead" ) ) {
                osmmap_config.load_ahead = !osmmap_config.load_ahead;
                osmmap_location->load_ahead = osmmap_config.load_ahead;
            }
            else if ( !strcmp( lv_list_get_btn_text( obj ), "autostart gps" ) ) {
                osmmap_config.gps_autoon = !osmmap_config.gps_autoon;
                gpsctl_set_autoon( osmmap_config.gps_autoon );
            }
            else if ( !strcmp( lv_list_get_btn_text( obj ), "autostart wifi" ) ) {
                osmmap_config.wifi_autoon = !osmmap_config.wifi_autoon;
                wifictl_set_autoon( osmmap_config.load_ahead );
            }
            osmmap_app_set_setting_menu( sub_menu_setting );
            break;
    }
}

/**
 * @brief when osm is active, this task get the use inactive time and hide
 * the statusbar and icon.
 */
void osmmap_main_tile_update_task( lv_task_t * task ) {
    /*
     * check if maintile alread initialized
     */
    if ( osmmap_app_active ) {
        if ( last_touch + 5000 < millis() ) {
            lv_obj_set_hidden( layers_btn, true );
            lv_obj_set_hidden( exit_btn, true );
            lv_obj_set_hidden( zoom_in_btn, true );
            lv_obj_set_hidden( zoom_out_btn, true );
            lv_obj_set_hidden( zoom_northwest_btn, true );
            lv_obj_set_hidden( zoom_northeast_btn, true );
            lv_obj_set_hidden( zoom_southwest_btn, true );
            lv_obj_set_hidden( zoom_southeast_btn, true );
            lv_obj_set_hidden( north_btn, true );
            lv_obj_set_hidden( south_btn, true );
            lv_obj_set_hidden( west_btn, true );
            lv_obj_set_hidden( east_btn, true );
            lv_obj_set_hidden( sub_menu_layers, true );
            lv_obj_set_hidden( sub_menu_setting, true );
        }
        else {
            lv_obj_set_hidden( layers_btn, false );
            lv_obj_set_hidden( exit_btn, false );
            lv_obj_set_hidden( zoom_in_btn, false );
            lv_obj_set_hidden( zoom_out_btn, false );
            lv_obj_set_hidden( zoom_northwest_btn, false );
            lv_obj_set_hidden( zoom_northeast_btn, false );
            lv_obj_set_hidden( zoom_southwest_btn, false );
            lv_obj_set_hidden( zoom_southeast_btn, false );
            lv_obj_set_hidden( north_btn, false );
            lv_obj_set_hidden( south_btn, false );
            lv_obj_set_hidden( west_btn, false );
            lv_obj_set_hidden( east_btn, false );
        }
    }
}

bool osmmap_gpsctl_event_cb( EventBits_t event, void *arg ) {
    gps_data_t *gps_data = NULL;
    char lonlat[64] = "";
    
    switch ( event ) {
        case GPSCTL_SET_APP_LOCATION:
            /**
             * update location and tile map image on new location
             */
            gps_data = ( gps_data_t *)arg;
            osm_map_set_lon_lat( osmmap_location, gps_data->lon, gps_data->lat );
            snprintf( lonlat, sizeof( lonlat ), "%f° / %f°", gps_data->lat, gps_data->lon );
            lv_label_set_text( osmmap_lonlat_label, (const char*)lonlat );
            if ( osmmap_app_active )
                osmmap_update_request();
            break;
        case GPSCTL_UPDATE_LOCATION:
            /**
             * update location and tile map image on new location
             */
            gps_data = ( gps_data_t *)arg;
            osm_map_set_lon_lat( osmmap_location, gps_data->lon, gps_data->lat );
            snprintf( lonlat, sizeof( lonlat ), "%f° / %f°", gps_data->lat, gps_data->lon );
            lv_label_set_text( osmmap_lonlat_label, (const char*)lonlat );
            if ( osmmap_app_active )
                osmmap_update_request();
            break;
    }
    return( true );
}


void osmmap_update_request( void ) {
    /**
     * check if another osm tile image update is running
     */
    if ( xEventGroupGetBits( osmmap_event_handle ) & OSM_APP_TILE_IMAGE_REQUEST ) {
        return;
    }
    else {
        xEventGroupSetBits( osmmap_event_handle, OSM_APP_TILE_IMAGE_REQUEST );
    }
}

void osmmap_update_Task( void * pvParameters ) {
    OSMMAP_APP_LOG("start osm map tile background update task, heap: %d", ESP.getFreeHeap() );
    while( 1 ) {
        /**
         * check if a tile image update is requested
         */
        if ( xEventGroupGetBits( osmmap_event_handle ) & OSM_APP_TILE_IMAGE_REQUEST ) {
            /**
             * check if a tile image update is required and update them
             */
            if( osm_map_update( osmmap_location ) ) {
                if ( osm_map_get_tile_image( osmmap_location ) ) {
                    lv_img_set_src( osmmap_app_tile_img, osm_map_get_tile_image( osmmap_location ) );
                }
                lv_obj_align( osmmap_app_tile_img, lv_obj_get_parent( osmmap_app_tile_img ), LV_ALIGN_CENTER, 0 , 0 );
            }
            /**
             * update postion point on the tile image when is valid
             */
            if ( osmmap_location->tilexy_pos_valid ) {
                lv_obj_align( osmmap_app_pos_img, lv_obj_get_parent( osmmap_app_pos_img ), LV_ALIGN_IN_TOP_LEFT, osmmap_location->tilex_pos - 8 , osmmap_location->tiley_pos - 8 );
                lv_obj_set_hidden( osmmap_app_pos_img, false );
            }
            else {
                lv_obj_set_hidden( osmmap_app_pos_img, true );
            }
            /**
             * clear update request flag
             */
            xEventGroupClearBits( osmmap_event_handle, OSM_APP_TILE_IMAGE_REQUEST );
        }
        else {
            /**
             * check if load ahead need or finsh
             */
            osm_map_load_tiles_ahead( osmmap_location );
        }
        /**
         * check if for a task exit request
         */
        if ( xEventGroupGetBits( osmmap_event_handle ) & OSM_APP_TASK_EXIT_REQUEST ) {
            xEventGroupClearBits( osmmap_event_handle, OSM_APP_TASK_EXIT_REQUEST );
            break;
        }
        /**
         * block this task for 125ms
         */
        vTaskDelay( 25 );
    }
    OSMMAP_APP_LOG("finsh osm map tile background update task, heap: %d", ESP.getFreeHeap() );
    vTaskDelete( NULL );    
}

static void exit_osmmap_app_main_event_cb( lv_obj_t * obj, lv_event_t event ) {
    switch( event ) {
        case( LV_EVENT_CLICKED ):
            /**
             * exit to mainbar
             */
            mainbar_jump_to_maintile( LV_ANIM_OFF );
            break;
    }
}

static void nav_direction_osmmap_app_main_event_cb( lv_obj_t * obj, lv_event_t event ) {
    switch( event ) {
        /**
         * long press event for center
         */
        case( LV_EVENT_LONG_PRESSED ):
            OSMMAP_APP_LOG("center map to pos");
            osm_map_center_location( osmmap_location );
            osmmap_update_request();
            break;
        /**
         * short press event to move
         */   
        case( LV_EVENT_SHORT_CLICKED ):
            if ( obj == north_btn ) {
                OSMMAP_APP_LOG("nav north direction");
                osm_map_nav_direction( osmmap_location, north );
            }
            else if ( obj == south_btn ) {
                OSMMAP_APP_LOG("nav south direction");
                osm_map_nav_direction( osmmap_location, south );
            }
            else if ( obj == west_btn ) {
                OSMMAP_APP_LOG("nav west direction");
                osm_map_nav_direction( osmmap_location, west );
            }
            else if ( obj == east_btn ) {
                OSMMAP_APP_LOG("nav east direction");
                osm_map_nav_direction( osmmap_location, east );
            }
            else {
                OSMMAP_APP_LOG("direction source unknown");
            }
            if ( osmmap_app_active )
                osmmap_update_request();
            break;
    }
}

static void nav_center_osmmap_app_main_event_cb( lv_obj_t * obj, lv_event_t event ) {
    switch( event ) {
        /**
         * long press event for center
         */
        case( LV_EVENT_LONG_PRESSED ):
            OSMMAP_APP_LOG("center map to pos");
            osm_map_center_location( osmmap_location );
            osmmap_update_request();
            break;
        /**
         * short press event to zoom in
         */
        case( LV_EVENT_SHORT_CLICKED ):
            if ( obj == zoom_northwest_btn ) {
                OSMMAP_APP_LOG("nav northwest center");
                osm_map_nav_direction( osmmap_location, zoom_northwest );
            }
            else if ( obj == zoom_northeast_btn ) {
                OSMMAP_APP_LOG("nav northeast center");
                osm_map_nav_direction( osmmap_location, zoom_northeast );
            }
            else if ( obj == zoom_southwest_btn ) {
                OSMMAP_APP_LOG("nav southwest center");
                osm_map_nav_direction( osmmap_location, zoom_southwest );
            }
            else if ( obj == zoom_southeast_btn ) {
                OSMMAP_APP_LOG("nav southeast center");
                osm_map_nav_direction( osmmap_location, zoom_southeast );
            }
            else {
                OSMMAP_APP_LOG("zoom source unknown");
                osm_map_nav_direction( osmmap_location, east );
            }
            if ( osmmap_app_active )
                osmmap_update_request();
            break;
    }
}

static void zoom_in_osmmap_app_main_event_cb( lv_obj_t * obj, lv_event_t event ) {
    switch( event ) {
        case( LV_EVENT_CLICKED ):   
            /**
             * increase zoom level
             */
            osm_map_zoom_in( osmmap_location );
            if ( osmmap_app_active )
                osmmap_update_request();
            break;
    }
}

static void zoom_out_osmmap_app_main_event_cb( lv_obj_t * obj, lv_event_t event ) {
    switch( event ) {
        case( LV_EVENT_CLICKED ):   
            /**
             * decrease zoom level
             */
            osm_map_zoom_out( osmmap_location );
            if ( osmmap_app_active )
                osmmap_update_request();
            break;
    }
}

static void layers_btn_app_main_event_cb( lv_obj_t * obj, lv_event_t event ) {
    switch( event ) {
        case( LV_EVENT_CLICKED ):
            if ( lv_obj_get_hidden( sub_menu_setting ) ) {
                osmmap_app_set_setting_menu( sub_menu_setting );
                lv_obj_set_hidden( sub_menu_setting, false );
            }
            else {
                lv_obj_set_hidden( sub_menu_setting, true );
                lv_obj_set_hidden( sub_menu_layers, true );
            }
            break;
    }
}

static void osmmap_tile_server_event_cb( lv_obj_t * obj, lv_event_t event ) {
    switch( event ) {
        case LV_EVENT_CLICKED: {
            SpiRamJsonDocument doc( strlen( (const char*)osm_server_json_start ) * 2 );
            DeserializationError error = deserializeJson( doc, (const char *)osm_server_json_start );

            if ( error ) {
                OSMMAP_APP_ERROR_LOG("osm server list deserializeJson() failed: %s", error.c_str() );
            }
            else {
                const char *tile_server = doc[ lv_list_get_btn_text( obj ) ];
                OSMMAP_APP_INFO_LOG("new tile server url: %s", tile_server );
                osm_map_set_tile_server( osmmap_location, tile_server );
                strncpy( osmmap_config.osmmap, lv_list_get_btn_text( obj ), sizeof( osmmap_config.osmmap ) );
                osmmap_add_tile_server_list( sub_menu_layers );
                osmmap_update_request();
            }
            doc.clear();
            lv_obj_set_hidden( sub_menu_layers, true );            
            break;
        }
    }
}

void osmmap_add_tile_server_list( lv_obj_t *layers_list ) {
    lv_obj_t * list_btn;
    

    SpiRamJsonDocument doc( strlen( (const char*)osm_server_json_start ) * 2 );
    DeserializationError error = deserializeJson( doc, (const char *)osm_server_json_start );

    if ( error ) {
        OSMMAP_APP_ERROR_LOG("osm server list deserializeJson() failed: %s", error.c_str() );
    }
    else {
        while ( lv_list_remove( layers_list, 0 ) );
        JsonObject obj = doc.as<JsonObject>();
        for ( JsonPair p : obj ) {
            OSMMAP_APP_LOG("server: %s", p.key().c_str() );
            list_btn = lv_list_add_btn( layers_list, !strcmp( osmmap_config.osmmap, p.key().c_str() ) ? &checked_dark_16px : &unchecked_dark_16px, p.key().c_str() );
            lv_obj_set_event_cb( list_btn, osmmap_tile_server_event_cb );
            if ( !strcmp( osmmap_config.osmmap, p.key().c_str() ) ) {
                const char *osmmap_url = doc[ p.key().c_str() ];
                OSMMAP_APP_INFO_LOG("set osmmap url: %s, %s", p.key().c_str(), osmmap_url );
                osm_map_set_tile_server( osmmap_location, osmmap_url );
            }
        }        
    }
    doc.clear();
}

void osmmap_activate_cb( void ) {
    /**
     * save block show messages state
     */
    osmmap_gps_state = gpsctl_get_autoon();
    if( osmmap_config.gps_autoon ) {
        gpsctl_on();
    }
    /**
     * save block show messages state
     */
    osmmap_wifi_state = wifictl_get_autoon();
    if( osmmap_config.wifi_autoon ) {
        wifictl_on();
        wifictl_set_autoon( osmmap_config.wifi_autoon );
    }
    /**
     * save block show messages state
     */
    osmmap_block_show_messages = blectl_get_show_notification();
    /**
     * save black return to maintile state
     */
    osmmap_block_return_maintile = display_get_block_return_maintile();
    display_set_block_return_maintile( true );
    /**
     * save statusbar force dark mode state
     */
    osmmap_statusbar_force_dark_mode = statusbar_get_force_dark();
    statusbar_set_force_dark( true );
    /**
     * force redraw screen
     */
    lv_obj_invalidate( lv_scr_act() );
    statusbar_hide( true );
    /**
     * set osm app active
     */
    osmmap_app_active = true;
    /**
     * start background osm tile image update Task
     */
    xTaskCreate(    osmmap_update_Task,      /* Function to implement the task */
                    "osmmap update Task",    /* Name of the task */
                    5000,                            /* Stack size in words */
                    NULL,                            /* Task input parameter */
                    1,                               /* Priority of the task */
                    &_osmmap_download_Task );  /* Task handle. */

    osmmap_update_request();
    lv_img_cache_invalidate_src( osmmap_app_tile_img );
}

void osmmap_hibernate_cb( void ) {
    /**
     * restore back to maintile and status force dark mode
     */
    blectl_set_show_notification( osmmap_block_show_messages );
    display_set_block_return_maintile( osmmap_block_return_maintile );
    statusbar_set_force_dark( osmmap_statusbar_force_dark_mode );
    gpsctl_set_autoon( osmmap_gps_state );
    wifictl_set_autoon( osmmap_wifi_state );
    /**
     * set osm app inactive
     */
    osmmap_app_active = false;
    statusbar_hide( false );
    /**
     * stop background osm tile image update Task
     */
    xEventGroupSetBits( osmmap_event_handle, OSM_APP_TASK_EXIT_REQUEST );
    osmmap_config.save();
}
