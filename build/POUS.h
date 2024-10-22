#include "beremiz.h"
#ifndef __POUS_H
#define __POUS_H

#include "accessor.h"
#include "iec_std_lib.h"

__DECLARE_ENUMERATED_TYPE(LOGLEVEL,
  LOGLEVEL__CRITICAL,
  LOGLEVEL__WARNING,
  LOGLEVEL__INFO,
  LOGLEVEL__DEBUG
)
// FUNCTION_BLOCK LOGGER
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,TRIG)
  __DECLARE_VAR(STRING,MSG)
  __DECLARE_VAR(LOGLEVEL,LEVEL)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(BOOL,TRIG0)

} LOGGER;

void LOGGER_init__(LOGGER *data__, BOOL retain);
// Code part
void LOGGER_body__(LOGGER *data__);
// PROGRAM PROGRAM0
// Data part
typedef struct {
  // PROGRAM Interface - IN, OUT, IN_OUT variables

  // PROGRAM private variables - TEMP, private and located variables
  __DECLARE_LOCATED(BOOL,RED)
  __DECLARE_LOCATED(BOOL,GREEN)
  __DECLARE_LOCATED(BOOL,BLUE)
  __DECLARE_LOCATED(INT,LIGHT_SENSOR)
  __DECLARE_VAR(INT,LIGHT_THRESHOLD)
  __DECLARE_LOCATED(BOOL,CORRECT_PIN)
  __DECLARE_LOCATED(BOOL,INCORRECT_PIN)
  __DECLARE_VAR(BOOL,TRU)
  SR IS_OPEN;
  R_TRIG R_TRIG1;
  R_TRIG R_TRIG2;
  __DECLARE_VAR(BOOL,_TMP_AND36_OUT)
  __DECLARE_VAR(BOOL,_TMP_LT16_OUT)
  __DECLARE_VAR(BOOL,_TMP_AND31_OUT)

} PROGRAM0;

void PROGRAM0_init__(PROGRAM0 *data__, BOOL retain);
// Code part
void PROGRAM0_body__(PROGRAM0 *data__);
#endif //__POUS_H
