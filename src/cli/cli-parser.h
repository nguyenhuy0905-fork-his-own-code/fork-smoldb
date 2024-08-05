#ifndef SMOLDB_CLI_CLI_PARSER_H
#define SMOLDB_CLI_CLI_PARSER_H

#include "cli-handler.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Parse and then execute the input
 *
 * @param buf The input passed in
 * @return A signal (anything but SMOLDB_READ_ERR and SMOLDB_MORE_READ, defined
 * as SMOLDB_INPUT_READ_RETVAL) if succeeded, SMOLDB_READ_ERR if parse error,
 * SMOLDB_READ_MORE if another prompt is needed
 */
int smoldb_parse_input(const InputBuf *buf); // NOLINT(modernize-use-trailing-return-type)

#ifdef __cplusplus
}
#endif

#endif // !SMOLDB_CLI_CLI_PARSER_H
