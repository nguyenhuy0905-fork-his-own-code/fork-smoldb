#include "cli-handler.h"
#include "cli-parser.h"

#include <stdio.h>
#include <stdlib.h>

#include "retval.h"

/**
 * @brief Prints the nice looking prompt
 */
static inline void print_prompt() { printf(">>> "); }

int smoldb_new_input_buf(InputBuf **buf) {
  if (buf == NULL) {
    return SMOLDB_NULL_PTR_TO_REF_ERR;
  }

  (*buf) = (InputBuf *)malloc(sizeof(InputBuf));
  if ((*buf) == NULL) {
    return SMOLDB_ALLOC_ERR;
  }

  (*buf)->buffer = NULL;
  (*buf)->buf_len = 0;

  return SMOLDB_ALLOC_SUCCESS;
}

int smoldb_free_input_buf(InputBuf **buf) {
  if (buf == NULL) {
    return SMOLDB_ALLOC_SUCCESS;
  }

  free((*buf)->buffer);
  (*buf)->buffer = NULL;
  free((*buf));
  (*buf) = NULL;

  return SMOLDB_ALLOC_SUCCESS;
}

int smoldb_handle_input(InputBuf *const buf) {
  if (buf == NULL) {
    return SMOLDB_NULL_PTR_TO_REF_ERR;
  }
  print_prompt();
  size_t n_alloc = 0;
  buf->buf_len = getline(&buf->buffer, &n_alloc, stdin);
  return 0;
}
