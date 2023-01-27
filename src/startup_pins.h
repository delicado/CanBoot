
#ifndef __STARTUP_PINS_H
#define __STARTUP_PINS_H

struct startup_pin_s {
    int pin;
    uint8_t flags;
};

enum { SP_OUT_HIGH = 1 };

// out/compile_time_request.c (auto generated file)
extern const struct startup_pin_s startup_pins[];
extern const int startup_pins_size;

void startup_pins_setup(void);

#endif // startup_pins.h
