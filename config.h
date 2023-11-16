// Copyright 2023 markb (@Med116)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
#define WS2812_DI_PIN B3
#define RGBLED_NUM 64
#define RGBLIGHT_SLEEP
#define RGBLIGHT_DEFAULT_VAL 155
#define RGBLIGHT_LIMIT_VAL 180
#define RGBLIGHT_LAYERS
#define RGBLIGHT_LAYERS_RETAIN_VAL // to make lighting layers retain the current val ( not their own brightness )
#define RGBLIGHT_VAL_STEP 5
#define BOOTMAGIC_LITE_ROW 0
#define BOOTMAGIC_LITE_COLUMN 0
#define RGBLIGHT_HUE_STEP 8
#define RGBLIGHT_SAT_STEP 8

