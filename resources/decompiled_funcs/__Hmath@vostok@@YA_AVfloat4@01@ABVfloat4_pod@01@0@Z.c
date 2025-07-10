vostok::math::float4 *__cdecl vostok::math::operator+(
        vostok::math::float4 *result,
        const vostok::math::float4_pod *left,
        const vostok::math::float4_pod *right)
{
  vostok::math::float4 *v3; // eax

  v3 = result;
  result->x = left->x + right->x;
  result->y = left->y + right->y;
  result->z = left->z + right->z;
  result->w = left->w + right->w;
  return v3;
}
