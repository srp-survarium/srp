vostok::math::float2 *__fastcall vostok::math::operator-(
        const vostok::math::float2_pod *right,
        const vostok::math::float2_pod *left,
        vostok::math::float2 *a3)
{
  vostok::math::float2 *result; // eax

  result = a3;
  a3->x = left->x - right->x;
  a3->y = left->y - right->y;
  return result;
}
