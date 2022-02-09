#include "lamp.h"
#include <stdlib.h>
#include <stdio.h>

typedef enum state_e {
    ON,
    OFF
} state_t;

struct lamp_s {
    switchable_t * s;
    state_t state;
};

static switchable_error_t lamp_turn_on(switchable_t * s);
static switchable_error_t lamp_turn_off(switchable_t * s);

static const switchable_implementation_t lamp_switchable = {
    .switchable_turn_off = lamp_turn_off,
    .switchable_turn_on = lamp_turn_on
};

lamp_error_t lamp_create(lamp_t ** l) {
    lamp_t * lamp = (lamp_t *)malloc(sizeof(lamp_t));
    lamp->s = (switchable_t *)malloc(sizeof(switchable_t));
    lamp->s->implementation=&lamp_switchable;
    lamp->s->data = lamp;
    lamp->state = OFF;
    *l = lamp;
    return LAMP_SUCCESS;
}

lamp_error_t lamp_get_switch(lamp_t * l, switchable_t ** s) {
    *s = l->s;
    return LAMP_SUCCESS;
}

lamp_error_t lamp_destroy(lamp_t ** l) {
    free((*l)->s);
    free(*l);
    *l = NULL;
    return LAMP_SUCCESS;
}

static switchable_error_t lamp_turn_on(switchable_t * s) {
    lamp_t * lamp = s->data;
    if (lamp->state == OFF) {
        printf("Turning on the lamp %p\n", (void*) lamp);
        lamp->state = ON;
        return SWITCHABLE_SUCCESS;
    } else {
        printf("The lamp %p was already on\n", (void*) lamp);
        return SWITCHABLE_FAIL;
    }
}

static switchable_error_t lamp_turn_off(switchable_t * s) {
    lamp_t * lamp = s->data;
    if (lamp->state == ON) {
        printf("Turning off the lamp %p\n", (void*) lamp);
        lamp->state = OFF;
        return SWITCHABLE_SUCCESS;
    } else {
        printf("The lamp %p was already off\n", (void*) lamp);
        return SWITCHABLE_FAIL;
    }
}
