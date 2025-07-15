double __cdecl vostok::math::get_tangent_from_2d_vector(const vostok::math::float2 *vec)
{
  double y; // st7

  y = vec->y;
  if ( vec->x <= 0.0000099999997 )
    return y / 0.0000099999997;
  else
    return y / vec->x;
}
