double __cdecl vostok::particle::random_float(float min_value, float max_value)
{
  float alpha; // [esp+14h] [ebp-4h]

  alpha = (double)vostok::math::random32::random(&randomizer_64, 0xFFFFu) / 65535.0;
  return vostok::particle::linear_interpolation<float>(min_value, max_value, alpha);
}
