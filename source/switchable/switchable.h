#ifndef _SWITCHABLE_H_
#define _SWITCHABLE_H_

// Base definitions: the interface type and its error codes

typedef struct switchable_s switchable_t;

typedef enum switchable_error_e {
    SWITCHABLE_SUCCESS,
    SWITCHABLE_FAIL
} switchable_error_t;

// Implementer's interface: the implementation structure, and the
// object-implementation link.

typedef struct switchable_implementation_s switchable_implementation_t;

struct switchable_implementation_s {
    switchable_error_t (*switchable_turn_on)(switchable_t * s);
    switchable_error_t (*switchable_turn_off)(switchable_t * s);
};

struct switchable_s {
    switchable_implementation_t const * implementation;
    void * data; 
};

// Public interface: what applications use to handle switchable objects.

/**
 * @brief Turns on the switchable object.
 * 
 * @param s : A switchable object.
 * @return switchable_error_t 
 *      - SWITCHABLE_SUCCESS if the target object was turned on.
 *      - SWITCHABLE_FAIL if the target object failed to turn on.
 */
static inline switchable_error_t switchable_turn_on(switchable_t * s) {
    return s->implementation->switchable_turn_on(s);
}

/**
 * @brief Turns off the switchable object.
 * 
 * @param s : A switchable object.
 * @return switchable_error_t 
 *      - SWITCHABLE_SUCCESS if the target object was turned off.
 *      - SWITCHABLE_FAIL if the target object failed to turn off.
 */
static inline switchable_error_t switchable_turn_off(switchable_t * s) {
    return s->implementation->switchable_turn_off(s);
}

#endif
