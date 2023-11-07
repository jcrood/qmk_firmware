#ifndef USERSPACE
#define USERSPACE

#include "quantum.h"

// mac stuff
#define CMDGRV LGUI(KC_GRV)             // cmd ` - focus to next window
#define LOCKSCR LCTL(LGUI(KC_Q))        // ctrl cmd Q  - lock screen
#define CAPSCR SGUI(KC_3)               // shift cmd 3 - capture screen
#define CAPSEL SGUI(KC_4)               // shift cmd 4 - capture selection



void my_custom_function(void);

#endif