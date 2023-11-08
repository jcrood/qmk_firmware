RGB_MATRIX_EFFECT(LARSON_SCANNER)

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

#define BAR_WIDTH 20
#define BRIGHTNESS_STEP 6

uint8_t brightness[RGB_MATRIX_LED_COUNT];

static bool LARSON_SCANNER(effect_params_t* params) {  
    if (params->init) {
        memset(brightness, 0, sizeof(brightness));
    }
    
    uint8_t time = scale16by8(g_rgb_timer, qadd8(rgb_matrix_config.speed / 4, 1));
    uint8_t x_pos = scale8(sin8(time), 224 + 1);
    int8_t dir = time < 128 ? 1 : -1;

    uint8_t x_min = dir > 0 ? MAX((x_pos - BAR_WIDTH/2), 0) : MAX((x_pos - BAR_WIDTH/2), 0);
    uint8_t x_max = dir > 0 ? MIN((x_pos + BAR_WIDTH/2), 224) : MIN((x_pos + BAR_WIDTH/2), 224);

    HSV hsv = rgb_matrix_config.hsv;
    
    RGB_MATRIX_USE_LIMITS(led_min, led_max);
    
    for (uint8_t i = led_min; i < led_max; i++) {
      RGB_MATRIX_TEST_LED_FLAGS();
      
      uint8_t px = g_led_config.point[i].x;
  
      if (px >= x_min && px <= x_max) {
          brightness[i] = hsv.v;
      } 
    }
    
    if (led_max == RGB_MATRIX_LED_COUNT) {
        HSV newhsv = rgb_matrix_config.hsv;
    
        for (uint8_t i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
            newhsv.v = brightness[i];
            RGB rgb = rgb_matrix_hsv_to_rgb(newhsv);
            rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
            brightness[i] = qsub8(brightness[i], BRIGHTNESS_STEP);
        }
    }

    return rgb_matrix_check_finished_leds(led_max);
}

#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
