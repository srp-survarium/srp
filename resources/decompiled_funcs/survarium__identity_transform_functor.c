vostok::math::float4x4 *__cdecl survarium::identity_transform_functor(vostok::math::float4x4 *result)
{
  vostok::math::float4x4 *v1; // esi
  vostok::math::float4x4 *v2; // eax
  vostok::math::float4x4 v3; // [esp+8h] [ebp-40h] BYREF

  v1 = vostok::math::float4x4::identity(&v3);
  v2 = result;
  qmemcpy((void *)result, v1, sizeof(vostok::math::float4x4));
  return v2;
}
