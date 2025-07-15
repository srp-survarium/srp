__int64 __usercall convert_stick_value@<xmm0>(const __int16 value@<ax>, const unsigned __int16 dead_zone@<cx>)
{
  float v2; // xmm0_4
  __int64 result; // xmm0_8

  if ( value > (int)dead_zone )
  {
    v2 = (float)(value - dead_zone);
LABEL_3:
    *(float *)&result = v2 / (float)(32767.0 - (float)dead_zone);
    return result;
  }
  if ( value < -dead_zone )
  {
    v2 = (float)(dead_zone + value) + s_bm_current_air_resistance;
    goto LABEL_3;
  }
  return 0;
}
