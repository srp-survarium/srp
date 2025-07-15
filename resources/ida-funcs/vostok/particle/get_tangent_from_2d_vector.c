double __cdecl vostok::particle::get_tangent_from_2d_vector(const vostok::math::float2 *vec)
{
  float x; // xmm0_4

  x = vec->x;
  vostok::math::max();
  return (float)(vec->y / x);
}
