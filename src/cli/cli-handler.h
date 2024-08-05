/**
 * @file cli-handler
 * @brief Declares a set of functions to receive and handle user inputs
 */

#ifndef SMOLDB_CLI_CLI_HANDLER_H
#define SMOLDB_CLI_CLI_HANDLER_H

#include <stdint.h>

/* So that the code runs with Cpp */
#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

/**
 * @typedef InputBuf
 * @brief Holds information about user input or input from stdin
 *
 */
typedef struct InputBuf InputBuf;

struct InputBuf {
  char *buffer;
  __ssize_t buf_len;
};

/**
 * @brief Allocate memory for a new input buffer
 *
 * @param buf The pointer to the address of the input buffer to be allocated
 * memory
 * @return 0 if successful, something else if error, defined in retval.h
 */
int smoldb_new_input_buf(InputBuf **buf);

/**
 * @brief Free memory allocated to the input buffer specified, if any, and
 * points the pointer to NULL.
 *
 * @param buf The pointer to the address of the input buffer to be freed
 * memory. After being freed, (*buf) = NULL.
 * @return 0 if successful or if buf is NULL (hence nothing to remove)
 */
int smoldb_free_input_buf(InputBuf **buf);

/**
 * @brief Create prompt to get user input, and write the input to buf
 *
 * @param buf The buffer created
 * @return 0 if operation succeeded. SMOLDB_NULL_PTR_TO_REF_ERR if buf == NULL.
 * (More like, I don't know what to return either)
 */
int smoldb_handle_input(InputBuf* buf);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // !SMOLDB_CLI_CLI_HANDLER_H
