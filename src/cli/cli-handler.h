/**
 * @file cli-handler
 * @brief Declares a set of functions to receive and handle user inputs
 */

#ifndef SMOLDB_CLI_HANDLER_H
#define SMOLDB_CLI_HANDLER_H

#include "general.h"

/* So that the code runs with Cpp */
#ifdef __cplusplus
extern "C" {
#endif  // __cplusplus

/**
 * @typedef InputBuf
 * @brief Holds information about user input or input from stdin. Basically a
 * more convenient string.
 *
 */
typedef struct InputBuf InputBuf;

/**
 * @brief Allocate memory for a new input buffer
 *
 * NOTE: (*buf) can be NULL, but (**buf) can NOT be NULL.
 *
 * @param buf The pointer to the address of the input buffer to be allocated
 * memory
 * @return 0 if successful, something else if error, defined in retval.h
 */
SMOL_API int smoldb_new_input_buf(InputBuf **buf);

/**
 * @brief Free memory allocated to the input buffer specified, if any, and
 * points the pointer to NULL.
 *
 * NOTE: (*buf) can be NULL, but (**buf) can NOT be NULL.
 *
 * @param buf The pointer to the address of the input buffer to be freed
 * memory. After being freed, (*buf) = NULL.
 * @return 0 if successful or if buf is NULL (hence nothing to remove)
 */
SMOL_API int smoldb_free_input_buf(InputBuf **buf);

/**
 * @brief Prompt and get user input
 *
 * @param buf
 * @return
 */
extern int smoldb_handle_input(InputBuf *buf);

#ifdef __cplusplus
}
#endif  // __cplusplus

#endif  // !SMOLDB_CLI_HANDLER_H
