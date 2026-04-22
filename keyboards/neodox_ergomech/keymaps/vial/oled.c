/* Copyright 2020 Josef Adamcik
  * Modification for VIA support and RGB underglow by Jens Bonk-Wiltfang
  *
  * This program is free software: you can redistribute it and/or modify
  * it under the terms of the GNU General Public License as published by
  * the Free Software Foundation, either version 2 of the License, or
  * (at your option) any later version.
  *
  * This program is distributed in the hope that it will be useful,
  * but WITHOUT ANY WARRANTY; without even the implied warranty of
  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  * GNU General Public License for more details.
  *
  * You should have received a copy of the GNU General Public License
  * along with this program.  If not, see <http://www.gnu.org/licenses/>.
  */

#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    }
    return rotation;
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_write_P(PSTR("LAYER"), false);
         oled_write_P(PSTR("_____"), false);
        oled_write_P(PSTR("\n\n"), false);

        switch (get_highest_layer(layer_state)) {
           case 0:  oled_write_P(PSTR("QWRTY"), false); break;
            case 1:  oled_write_P(PSTR("SYMBL"), false); break;
            case 2:  oled_write_P(PSTR(" NAV "), false); break;
            case 3:  oled_write_P(PSTR(" MODS"), false); break;
            case 4:  oled_write_P(PSTR("  4  "), false); break;
            case 5:  oled_write_P(PSTR("  5  "), false); break;
            case 6:  oled_write_P(PSTR("  6  "), false); break;
            case 7:  oled_write_P(PSTR("  7  "), false); break;
            case 8:  oled_write_P(PSTR("  8  "), false); break;
            case 9:  oled_write_P(PSTR("  9  "), false); break;
            default: oled_write_P(PSTR("  ?  "), false); break;
        }
    } else {
        oled_clear();
        oled_off();
    }
    return false;
}

#endif
