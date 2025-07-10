double __cdecl vostok::particle::calc_duration(float duration, float duration_variance)
{
  float max_value; // [esp+8h] [ebp-8h]

  max_value = vostok::particle::random_float(0.0, 1.0);
  return (float)vostok::particle::linear_interpolation<float>(
                  duration - duration_variance,
                  duration + duration_variance,
                  max_value);
}
