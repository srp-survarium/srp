vostok::math::float2 *__usercall convert_stick_values@<eax>(
        const __int16 y@<dx>,
        vostok::math::float2 *result@<eax>,
        __int16 x,
        unsigned __int16 dead_zone)
{
  float v4; // xmm0_4
  float v5; // xmm2_4
  float v6; // xmm2_4
  float v7; // xmm0_4

  v4 = 0.0;
  if ( y > (int)dead_zone )
  {
    v5 = (float)(y - dead_zone);
LABEL_3:
    v6 = v5 / (float)(32767.0 - (float)dead_zone);
    goto LABEL_7;
  }
  if ( y < -dead_zone )
  {
    v5 = (float)(dead_zone + y) + *(float *)&clear_value;
    goto LABEL_3;
  }
  v6 = 0.0;
LABEL_7:
  if ( x > (int)dead_zone )
  {
    v7 = (float)(x - dead_zone);
LABEL_11:
    v4 = v7 / (float)(32767.0 - (float)dead_zone);
    goto LABEL_12;
  }
  if ( x < -dead_zone )
  {
    v7 = (float)(dead_zone + x) + *(float *)&clear_value;
    goto LABEL_11;
  }
LABEL_12:
  result->x = v4;
  result->y = v6;
  return result;
}
