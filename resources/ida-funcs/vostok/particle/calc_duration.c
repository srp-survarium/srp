double __cdecl vostok::particle::calc_duration(float duration, float duration_variance)
{
  double v2; // st7

  v2 = vostok::particle::random_float(0.0, 1.0);
  return v2 * (duration + duration_variance) + (1.0 - v2) * (duration - duration_variance);
}
