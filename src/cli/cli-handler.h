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
 * @brief Holds information about user input or input from stdin
 *
 */
typedef struct InputBuf InputBuf;

/**
 * @brief Allocate memory for a new input buffer
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
 * @param buf The pointer to the address of the input buffer to be freed
 * memory. After being freed, (*buf) = NULL.
 * @return 0 if successful or if buf is NULL (hence nothing to remove)
 */
SMOL_API int smoldb_free_input_buf(InputBuf **buf);

/**
 * @brief Prototype to handle prompt. 
 *
 * @param InputBuf* buf 
 * @param argc the number of arguments 
 * @param args the list of the arguments. 
 *
 * The arguments argc and args are expected to be passed from main(). At least one
 * command-line argument other than the executable is expected. If the user writes
 * input, the function reallocates memory for buf's buffer string.
 *
 * @return If the user insert "mogging" when prompted, the function returns 0.
 * If user does not provide any command-line argument, or the argument is "exit",
 * the function returns 1.
*/
SMOL_API int prompt_prototype(InputBuf *buf, int argc, char *args[]);

#ifdef __cplusplus
}
#endif  // __cplusplus

#endif  // !SMOLDB_CLI_HANDLER_H

