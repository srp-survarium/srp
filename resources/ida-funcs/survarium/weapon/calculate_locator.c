vostok::math::float4x4 *__userpurge survarium::weapon::calculate_locator@<eax>(
        long double locator@<esi:edi>,
        __m128i a2@<xmm0>,
        vostok::math::float4x4 *this,
        const vostok::math::float4x4 *transform,
        const vostok::math::float4x4 *matrices,
        const unsigned int matrices_count)
{
  vostok::math::float4x4 *v7; // edx
  vostok::math::float4x4 v9; // [esp+Ch] [ebp-84h] BYREF
  vostok::math::float4x4 v10; // [esp+4Ch] [ebp-44h] BYREF
  unsigned __int16 v11; // [esp+98h] [ebp+8h]

  HIDWORD(locator) = &add;
  if ( (_S9_0 & 1) == 0 )
  {
    _S9_0 |= 1u;
    vostok::math::create_rotation_y(locator, a2, &add, 3.1415927);
  }
  v11 = *(_WORD *)(LODWORD(locator) + 96);
  vostok::math::mul4x3((const vostok::math::float4x4 *)(LODWORD(locator) + 32), &add, &v10);
  if ( v11 == 0xFFFF )
  {
    v7 = &v10;
  }
  else
  {
    vostok::math::mul4x3(&matrices[v11], &v10, &v9);
    v7 = &v9;
  }
  vostok::math::mul4x3(transform, v7, this);
  return this;
}
