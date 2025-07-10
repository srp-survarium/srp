double __cdecl vostok::particle::linear_interpolation<float>(float a, float b, float alpha)
{
  return (1.0 - alpha) * a + b * alpha;
}
