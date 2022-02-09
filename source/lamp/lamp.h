#ifndef _LAMP_H_
#define _LAMP_H_

#include "switchable/switchable.h"

typedef struct lamp_s lamp_t;

typedef enum lamp_error_e {
    LAMP_SUCCESS,
    LAMP_FAIL
} lamp_error_t;

// Application interface

/**
 * @brief Allocates a lamp object.
 * 
 * @param l: The address of the lamp pointer to initialize.
 * 
 * @return lamp_error_t 
 *      - LAMP_SUCCESS if the lamp gets successfully created.
 *      - LAMP_FAIL if the creation function fails.
 */
lamp_error_t lamp_create(lamp_t ** l);

/**
 * @brief Gets the lamp's switch object, that is linked to the lamp's
 * implementation of the switchable interface.
 * 
 * @param l: The address of the lamp pointer to initialize.
 * 
 * @return lamp_error_t 
 *      - LAMP_SUCCESS if the lamp gets successfully created.
 *      - LAMP_FAIL if the creation function fails.
 */

/**
 * @brief Gets the lamp's switch object, that is linked to the lamp's
 * implementation of the switchable interface.
 * 
 * @param l: A pointer to the lamp object.
 * @param s: A pointer to the switchable reference to set to the address of
 * the lamp's switch.
 * 
 * @return lamp_error_t 
 *      - LAMP_SUCCESS if the pointer `s` is set properly.
 *      - LAMP_FAIL if `s` pointer was not initialized. In this case, the
 *        application shouldn't use the `s` pointer.
 */
lamp_error_t lamp_get_switch(lamp_t * l, switchable_t ** s);

/**
 * @brief Destroys a lamp object and clears the passed reference to it.
 * 
 * @param l: A pointer to the lamp reference to destroy. If lamp_destroy is
 * successful, it gets set to NULL.
 * 
 * @return lamp_error_t 
 *      - LAMP_SUCCESS if the lamp object gets destroyed and the reference set
 *        to NULL.
 *      - LAMP_FAIL if the function fails to free the lamp object's memory.
 */
lamp_error_t lamp_destroy(lamp_t ** l);

#endif
