#include "cli-handler.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "retval.h"

#define RESET_ALL "\033[0m"

/* List of colors */

#define BLACK "\033[30m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGNETA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"
#define DEFAULT_COLOR "\033[39m"

/* List of formats */

#define BOLD "\033[1m"
#define DIM "\033[2m"
#define ITALIC "\033[3m"
#define UNDERLINE "\033[4m"
#define STRIKETHROUGH "\033[9m"
#define CLEAR_SCREEN "\033[H\033[J"

struct InputBuf {
  char *buffer;
  size_t buf_len;
};

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

/**
 * @brief Reads the input from stdin and write into the input buffer passed in.
 *
 * NOTE: This operation reallocates the input buffer's inner string once.
 *
 * @return SMOLDB_ALLOC_SUCCESS (0) if nothing goes wrong, SMOLDB_NULL_PTR_ERR
 * if buf is NULL, SMOLDB_ALLOC_ERR if memory reallocation fails.
 */
static int smoldb_get_input(InputBuf *buf) {
  if (buf == NULL) {
    return SMOLDB_NULL_PTR_ERR;
  }
  printf(">>> ");
  ssize_t byteread = getline(&buf->buffer, &buf->buf_len, stdin);
  if (byteread <= 0) {
    return SMOLDB_ALLOC_ERR;
  }
  // ignore newline
  buf->buf_len = -1 + byteread;
  buf->buffer[byteread - 1] = '\0';
  return SMOLDB_ALLOC_SUCCESS;
}

int smoldb_handle_input(InputBuf *buf) {
  while (true) {
    int retcode = smoldb_get_input(buf);
    if (retcode) {
      return retcode;
    }

    // FIXME: Placeholder only
    if (buf->buf_len == strlen(".exit") && strcmp(buf->buffer, ".exit") == 0) {
      printf(YELLOW "Exited!\n" RESET_ALL);
      // HACK: technically there is an allocation in smoldb_get_input
      return SMOLDB_ALLOC_SUCCESS;
    }
    printf(RED "Unknown command: " BOLD "%s\n" RESET_ALL, buf->buffer);
  }

  return SMOLDB_ALLOC_SUCCESS;
}
