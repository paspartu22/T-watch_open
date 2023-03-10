/****************************************************************************
 *   Tu May 22 21:23:51 2020
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
#ifndef _TOUCH_CALIBRATION_H
    #define _TOUCH_CALIBRATION_H
    
    #include "config.h"

    #define     LOCATION_ICON_SIZE      32

    enum {
        CALIBRATION_STATE_NONE = 0,
        CALIBRATION_STATE_START,
        CALIBRATION_STATE_BOTTOM_LEFT,
        CALIBRATION_STATE_TOP_LEFT,
        CALIBRATION_STATE_TOP_RIGHT,
        CALIBRATION_STATE_BOTTOM_RIGHT,
        CALIBRATION_STATE_DONE,
        CALIBRATION_STATE_EXIT,
        CALIBRATION_STATE_ABORT,
    };

    /**
     * @brief system touch calibration setup
     */
    void touch_calibration_tile_setup( void );
    /**
     * @brief get the calibration tile number
     * 
     * @return uint32_t 
     */
    uint32_t touch_calibration_get_tile_num( void );

#endif // _TOUCH_CALIBRATION_H