#include "lamp/lamp.h"

int main() {
    lamp_t * lamp;
    lamp_create(&lamp);
    switchable_t * lamp_switch;
    lamp_get_switch(lamp, &lamp_switch);
    switchable_turn_on(lamp_switch);
    switchable_turn_on(lamp_switch);
    switchable_turn_off(lamp_switch);
    lamp_destroy(&lamp);
    return 0;
}
