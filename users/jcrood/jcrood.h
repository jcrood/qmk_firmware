#ifndef USERSPACE
#define USERSPACE

#include "quantum.h"

enum custom_keycodes {
    M_UPDIR = SAFE_RANGE,
    NEW_SAFE_RANGE  //use "NEW_SAFE_RANGE" for keymap specific codes
};

// mac stuff
#define CMDGRV LGUI(KC_GRV)             // cmd ` - focus to next window
#define LOCKSCR LCTL(LGUI(KC_Q))        // ctrl cmd Q  - lock screen
#define CAPSCR SGUI(KC_3)               // shift cmd 3 - capture screen
#define CAPSEL SGUI(KC_4)               // shift cmd 4 - capture selection

#endif
