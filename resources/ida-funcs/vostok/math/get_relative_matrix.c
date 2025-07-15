vostok::math::float4x4 *__cdecl vostok::math::get_relative_matrix(
        vostok::math::float4x4 *result,
        const vostok::math::float4x4 *original_matrix,
        const vostok::math::float4x4 *parent_matrix)
{
  vostok::math::float4x4 *v3; // ecx
  vostok::math::float4x4 v5; // [esp+10h] [ebp-44h] BYREF

  if ( vostok::math::float4x4::try_invert(parent_matrix, &v5) )
  {
    vostok::math::mul4x3(&v5, original_matrix, result);
  }
  else
  {
    __debugbreak();
    qmemcpy(result, vostok::math::float4x4::identity(v3, &v5), sizeof(vostok::math::float4x4));
  }
  return result;
}
