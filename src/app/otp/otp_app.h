
#pragma once

    /**
     * @brief setup otp
     * 
     */
    void otp_app_setup( void );
    /**
     * @brief get to otp app tile number
     * 
     * @return uint32_t tilenumber
     */

    uint32_t otp_app_get_app_main_tile_num();
    void enter_otp_app_event_cb( lv_obj_t * obj, lv_event_t event );
    void exit_otp_app_main_event_cb( lv_obj_t * obj, lv_event_t event );

