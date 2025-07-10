vostok::math::float4x4 *__cdecl vostok::math::operator*(
        vostok::math::float4x4 *result,
        const vostok::math::float4x4 *left,
        const vostok::math::float4x4 *right)
{
  vostok::math::mul4x3(result, left, right);
  return result;
}
