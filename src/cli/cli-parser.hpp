#ifndef SMOLDB_CLI_PARSER_HPP
#define SMOLDB_CLI_PARSER_HPP

#include "cli-handler.h"
#include "retval.h"
#include <functional>
#include <string_view>

namespace smoldb_cli {

class state_automaton {
private:
  auto entry_state_handle_() -> SMOL_PARSE_STATE;

  auto meta_state_handle_() -> SMOL_PARSE_STATE;

  std::string_view m_buf;

  std::size_t m_curr_pos = 0;

  bool m_is_end = false;

public:
  explicit state_automaton(std::string_view buf) : m_buf(buf) {}
};

} // namespace smoldb_cli

// TODO: add C binding for smoldb_parse_input
extern "C" {}

#endif // !SMOLDB_CLI_PARSER_HPP
