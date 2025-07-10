vostok::math::float3 *__fastcall vostok::math::operator-(
        const vostok::math::float3_pod *right,
        const vostok::math::float3_pod *left,
        vostok::math::float3 *a3)
{
  vostok::math::float3 *result; // eax

  result = a3;
  a3->x = left->x - right->x;
  a3->y = left->y - right->y;
  a3->z = left->z - right->z;
  return result;
}
