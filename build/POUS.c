void LOGGER_init__(LOGGER *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->TRIG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MSG,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->LEVEL,LOGLEVEL__INFO,retain)
  __INIT_VAR(data__->TRIG0,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void LOGGER_body__(LOGGER *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  if ((__GET_VAR(data__->TRIG,) && !(__GET_VAR(data__->TRIG0,)))) {
    #define GetFbVar(var,...) __GET_VAR(data__->var,__VA_ARGS__)
    #define SetFbVar(var,val,...) __SET_VAR(data__->,var,__VA_ARGS__,val)

   LogMessage(GetFbVar(LEVEL),(char*)GetFbVar(MSG, .body),GetFbVar(MSG, .len));
  
    #undef GetFbVar
    #undef SetFbVar
;
  };
  __SET_VAR(data__->,TRIG0,,__GET_VAR(data__->TRIG,));

  goto __end;

__end:
  return;
} // LOGGER_body__() 





void PROGRAM0_init__(PROGRAM0 *data__, BOOL retain) {
  __INIT_LOCATED(BOOL,__QX0_2,data__->RED,retain)
  __INIT_LOCATED_VALUE(data__->RED,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_3,data__->GREEN,retain)
  __INIT_LOCATED_VALUE(data__->GREEN,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_4,data__->BLUE,retain)
  __INIT_LOCATED_VALUE(data__->BLUE,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(INT,__IW0,data__->LIGHT_SENSOR,retain)
  __INIT_LOCATED_VALUE(data__->LIGHT_SENSOR,0)
  __INIT_VAR(data__->LIGHT_THRESHOLD,450,retain)
  __INIT_LOCATED(BOOL,__IX0_6,data__->CORRECT_PIN,retain)
  __INIT_LOCATED_VALUE(data__->CORRECT_PIN,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_7,data__->INCORRECT_PIN,retain)
  __INIT_LOCATED_VALUE(data__->INCORRECT_PIN,__BOOL_LITERAL(FALSE))
  __INIT_VAR(data__->TRU,1,retain)
  SR_init__(&data__->IS_OPEN,retain);
  R_TRIG_init__(&data__->R_TRIG1,retain);
  R_TRIG_init__(&data__->R_TRIG2,retain);
  __INIT_VAR(data__->_TMP_AND36_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_LT16_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_AND31_OUT,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void PROGRAM0_body__(PROGRAM0 *data__) {
  // Initialise TEMP variables

  __SET_VAR(data__->R_TRIG1.,CLK,,__GET_LOCATED(data__->CORRECT_PIN,));
  R_TRIG_body__(&data__->R_TRIG1);
  __SET_VAR(data__->R_TRIG2.,CLK,,__GET_LOCATED(data__->INCORRECT_PIN,));
  R_TRIG_body__(&data__->R_TRIG2);
  __SET_VAR(data__->,_TMP_AND36_OUT,,AND__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (BOOL)__GET_VAR(data__->R_TRIG2.Q,),
    (BOOL)__GET_VAR(data__->IS_OPEN.Q1,)));
  __SET_VAR(data__->IS_OPEN.,S1,,__GET_VAR(data__->R_TRIG1.Q,));
  __SET_VAR(data__->IS_OPEN.,R,,__GET_VAR(data__->_TMP_AND36_OUT,));
  SR_body__(&data__->IS_OPEN);
  __SET_LOCATED(data__->,GREEN,,__GET_VAR(data__->IS_OPEN.Q1,));
  __SET_VAR(data__->,_TMP_LT16_OUT,,LT__BOOL__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (INT)__GET_LOCATED(data__->LIGHT_SENSOR,),
    (INT)__GET_VAR(data__->LIGHT_THRESHOLD,)));
  __SET_VAR(data__->,_TMP_AND31_OUT,,AND__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)1,
    (BOOL)__GET_VAR(data__->_TMP_LT16_OUT,)));
  __SET_LOCATED(data__->,BLUE,,__GET_VAR(data__->_TMP_AND31_OUT,));

  goto __end;

__end:
  return;
} // PROGRAM0_body__() 





