// Support setting gpio pins at mcu start
//
// Copyright (C) 2019  Kevin O'Connor <kevin@koconnor.net>
//
// This file may be distributed under the terms of the GNU GPLv3 license.

#include "autoconf.h" // CONFIG_INITIAL_PINS
#include "board/gpio.h" // gpio_out_setup
#include "board/pgm.h" // READP
#include "ctr.h" // DECL_CTR
#include "startup_pins.h" // initial_pins
#include "sched.h" // DECL_INIT

DECL_CTR("DECL_STARTUP_PINS " __stringify(CONFIG_STARTUP_PINS));

void
startup_pins_setup(void)
{
    if (sizeof(CONFIG_STARTUP_PINS) <= 1)
        return;
    int i;
    for (i=0; i<startup_pins_size; i++) {
        const struct startup_pin_s *ip = &startup_pins[i];
        gpio_out_setup(READP(ip->pin), READP(ip->flags) & SP_OUT_HIGH);
    }
}
