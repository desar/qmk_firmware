#pragma once

#include "progmem.h"
#include "fujitsu.c"

#ifdef OLED_DRIVER_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_keyboard_left()) {
        return OLED_ROTATION_0;
    } else {
		return OLED_ROTATION_180;
	}
}

void render_animation(uint8_t frame) {
	if(frame>=8) { 
		if(frame>=16) { frame = 24 - frame -1; }
		else { frame = 7; }
	}	

			
    oled_write_raw_P(animation[frame], sizeof(animation[frame]));
}

void oled_task_user(void) {
    render_animation((timer_read() / 120) % 24);
}
#endif