#include "cli-parser.hpp"
#include "retval.h"
#include <cassert>

namespace smoldb_cli {
auto state_automaton::entry_state_handle_() -> SMOL_PARSE_STATE {
  assert(m_curr_pos == 0);
  if(m_curr_pos >= m_buf.size()) {
    return SMOLDB_PARSE_ERR;
  }

  switch(m_buf.at(0)) {
    case '.':
      return SMOLDB_PARSE_META;
    default:
      // TODO: handle SQL parsing
      m_is_end = true;
      return SMOLDB_PARSE_SQL;
  }

  // never reaches here theoretically
  return SMOLDB_PARSE_ERR;
}

auto state_automaton::meta_state_handle_() -> SMOL_PARSE_STATE {
  assert(m_curr_pos >= 1);

  if(m_curr_pos >= m_buf.size()) {
    return SMOLDB_PARSE_ERR;
  }

  if(m_buf.substr(m_curr_pos) == "exit"){
    m_is_end = true;
    return SMOLDB_PARSE_META_EXIT;
  }

  return SMOLDB_PARSE_ERR;
}

} // namespace smoldb_cli
