double __cdecl vostok::math::cubic_interpolation<float,float>(float P0, float M0, float P1, float M1, float t)
{
  float t_pow_3; // [esp+4h] [ebp-Ch]

  t_pow_3 = (float)(t * t) * t;
  return (t_pow_3 - ((float)(t * t) + (float)(t * t)) + t) * M0
       + ((float)(t_pow_3 * 2.0) - (float)((float)(t * t) * 3.0) + *(float *)&clear_value) * P0
       + ((float)((float)(t * t) * 3.0) - (float)(t_pow_3 * 2.0)) * P1
       + (t_pow_3 - (float)(t * t)) * M1;
}
