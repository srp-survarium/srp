double __cdecl vostok::particle::cubic_interpolation<float,float>(float P0, float M0, float P1, float M1, float t)
{
  float t_pow_3; // [esp+4h] [ebp-4h]

  t_pow_3 = (float)(t * t) * t;
  return (2.0 * t_pow_3 - 3.0 * (float)(t * t) + *(float *)&clear_value) * P0
       + (t_pow_3 - 2.0 * (float)(t * t) + t) * M0
       + (-2.0 * t_pow_3 + 3.0 * (float)(t * t)) * P1
       + (t_pow_3 - (float)(t * t)) * M1;
}
