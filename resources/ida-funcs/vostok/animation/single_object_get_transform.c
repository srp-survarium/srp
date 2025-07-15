vostok::math::float4x4 *__cdecl vostok::animation::single_object_get_transform(
        vostok::math::float4x4 *result,
        const vostok::math::float4x4 *transform)
{
  vostok::math::float4x4 *v2; // eax

  v2 = result;
  qmemcpy((void *)result, transform, sizeof(vostok::math::float4x4));
  return v2;
}
