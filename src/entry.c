#include <stdlib.h>
#include <string.h>

#include "cli-handler.h"
#include "retval.h"

int main(/*int argc, char *argv[]*/) {
  // HACK: InputBuf is managed by main() due to the fact that its lifetime is
  // the same as the program's lifetime
  InputBuf *buf = NULL;
  int retval = smoldb_new_input_buf(&buf);
  if (retval == SMOLDB_ALLOC_ERR) {
    smoldb_free_input_buf(&buf);
    return EXIT_FAILURE;
  }
  smoldb_handle_input(buf);
  smoldb_free_input_buf(&buf);
  return EXIT_SUCCESS;
}
