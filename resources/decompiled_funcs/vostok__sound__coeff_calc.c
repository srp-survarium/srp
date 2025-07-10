double __cdecl vostok::sound::coeff_calc(float g, float cw)
{
  float v3; // [esp+0h] [ebp-Ch]
  float a; // [esp+8h] [ebp-4h]

  a = *(float *)&FLOAT_0_0;
  if ( g <= 0.0099999998 )
    v3 = 0.0099999998;
  else
    v3 = g;
  if ( v3 < 0.99989998 )
    return (float)((float)((float)(1.0 - (float)(v3 * cw))
                         - fsqrt(
                             (float)((float)(2.0 * v3) * (float)(1.0 - cw))
                           - (float)((float)(v3 * v3) * (float)(1.0 - (float)(cw * cw)))))
                 / (float)(1.0 - v3));
  return a;
}
