#ifndef SMOLDB_RETVAL_H
#define SMOLDB_RETVAL_H

#include "general.h"

/**
 * @typedef SMOL_ALLOC_RETVAL
 * @brief Defines the return codes from functions that allocate memory
 *
 */
SMOL_API typedef enum SMOL_ALLOC_RETVAL {
  /* Nothing special happened, and allocation was successful */
  SMOLDB_ALLOC_SUCCESS = 0,

  /* Malloc failed and returned NULL */
  SMOLDB_ALLOC_ERR,

  /* The pointer to address is NULL,
   * NOTE: this won't happen to NULL pointer (void*) but only to null
   * pointer-to-pointer (void**)
   *
   * */
  SMOLDB_NULL_PTR_TO_REF_ERR,
} SMOLDB_ALLOC_RETVAL;

/**
 * @typedef SMOL_INPUT_READ_RETVAL
 * @brief Defines the return codes from functions that read user input
 *
 */
SMOL_API typedef enum SMOL_INPUT_READ_RETVAL {
  SMOLDB_READ_SUCCESS = 0,
  SMOLDB_READ_ERR,
  SMOLDB_READ_MORE,
} SMOL_INPUT_READ_RETVAL;

typedef enum SMOL_PARSE_STATE {
  SMOLDB_PARSE_INITIAL,
  SMOLDB_PARSE_ERR,
  SMOLDB_PARSE_META, // .
  SMOLDB_PARSE_SQL,
  // metacommands
  SMOLDB_PARSE_META_EXIT, // .exit
  // TODO: add more metacommands
} SMOL_PARSE_STATE; 

#endif // !SMOLDB_RETVAL_H
