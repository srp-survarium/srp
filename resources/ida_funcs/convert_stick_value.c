__int64 __usercall convert_stick_value@<xmm0>(const __int16 value@<ax>, const unsigned __int16 dead_zone@<cx>)
{
  __int64 result; // xmm0_8

  if ( value <= (int)dead_zone )
  {
    if ( value >= -dead_zone )
      return 0;
    else
      *(float *)&result = (float)((float)(dead_zone + value) + *(float *)&clear_value)
                        / (float)(32767.0 - (float)dead_zone);
  }
  else
  {
    *(float *)&result = (float)(value - dead_zone) / (float)(32767.0 - (float)dead_zone);
  }
  return result;
}
