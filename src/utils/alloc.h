#ifndef _ALLOC_H
    #define _ALLOC_H

    #include <stdio.h>
    #include <stdlib.h>

    #if defined( BOARD_HAS_PSRAM )
        #include <stddef.h>
        #include <stdbool.h>
        #include <esp32-hal-psram.h>

        #define MALLOC         ps_malloc            /** @brief malloac from PSRAM */
        #define CALLOC         ps_calloc            /** @brief calloc from PSRAM */
        #define REALLOC        ps_realloc           /** @brief realloc from PSRAM */
    #else
        #define MALLOC         malloc               /** @brief malloac from normal heap */
        #define CALLOC         calloc               /** @brief calloc from normal heap */
        #define REALLOC        realloc              /** @brief realloc from normal heap */
    #endif // BOARD_HAS_PSRAM

    #define     ASSERT( test, message, ... ) do { if (!(test)) { log_e( "[A] %s (line:%d) " message "\r\n", __FILE__, __LINE__, ##__VA_ARGS__); while(true); } } while (0)

#endif // _ALLOC_H
