TYPE
  LOGLEVEL : (CRITICAL, WARNING, INFO, DEBUG) := INFO;
END_TYPE

FUNCTION_BLOCK LOGGER
  VAR_INPUT
    TRIG : BOOL;
    MSG : STRING;
    LEVEL : LOGLEVEL := INFO;
  END_VAR
  VAR
    TRIG0 : BOOL;
  END_VAR

  IF TRIG AND NOT TRIG0 THEN
  {{
   LogMessage(GetFbVar(LEVEL),(char*)GetFbVar(MSG, .body),GetFbVar(MSG, .len));
  }}
  END_IF;
  TRIG0:=TRIG;
END_FUNCTION_BLOCK


PROGRAM program0
  VAR
    red AT %QX0.2 : BOOL;
    green AT %QX0.3 : BOOL;
    blue AT %QX0.4 : BOOL;
    light_sensor AT %IW0 : INT;
  END_VAR
  VAR
    light_threshold : INT := 450;
  END_VAR
  VAR
    correct_pin AT %IX0.6 : BOOL;
    incorrect_pin AT %IX0.7 : BOOL;
  END_VAR
  VAR
    TRU : BOOL := 1;
    IS_OPEN : SR;
    R_TRIG1 : R_TRIG;
    R_TRIG2 : R_TRIG;
    _TMP_AND36_OUT : BOOL;
    _TMP_LT16_OUT : BOOL;
    _TMP_AND31_OUT : BOOL;
  END_VAR

  R_TRIG1(CLK := correct_pin);
  R_TRIG2(CLK := incorrect_pin);
  _TMP_AND36_OUT := AND(R_TRIG2.Q, IS_OPEN.Q1);
  IS_OPEN(S1 := R_TRIG1.Q, R := _TMP_AND36_OUT);
  green := IS_OPEN.Q1;
  _TMP_LT16_OUT := LT(light_sensor, light_threshold);
  _TMP_AND31_OUT := AND(_TMP_LT16_OUT);
  blue := _TMP_AND31_OUT;
END_PROGRAM


CONFIGURATION Config0

  RESOURCE Res0 ON PLC
    TASK task0(INTERVAL := T#20ms,PRIORITY := 0);
    PROGRAM instance0 WITH task0 : program0;
  END_RESOURCE
END_CONFIGURATION
