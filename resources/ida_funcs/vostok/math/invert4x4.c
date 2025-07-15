vostok::math::float4x4 *__fastcall vostok::math::invert4x4(
        const vostok::math::float4x4 *matrix_to_invert,
        vostok::math::float4x4 *a2)
{
  int v2; // edx

  vostok::math::try_invert4x4(matrix_to_invert, a2);
  return (vostok::math::float4x4 *)v2;
}
