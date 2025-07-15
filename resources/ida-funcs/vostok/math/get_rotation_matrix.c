vostok::math::float4x4 *__usercall vostok::math::get_rotation_matrix@<eax>(
        const vostok::math::float3 *original_dir@<ecx>,
        const vostok::math::float3 *target_dir@<eax>,
        vostok::math::float4x4 *a3)
{
  float y; // xmm5_4
  float z; // xmm6_4
  float v5; // xmm2_4
  vostok::math::float4x4 *v6; // ecx
  float v7; // xmm1_4
  __m128i v8; // xmm0
  unsigned int v9; // xmm2_4
  vostok::math::float4x4 *v10; // esi
  long double v12; // [esp+4h] [ebp-80h]
  long double v13; // [esp+Ch] [ebp-78h]
  float v14; // [esp+2Ch] [ebp-58h]
  float v15; // [esp+30h] [ebp-54h]
  float v16; // [esp+34h] [ebp-50h]
  vostok::math::float3 v17; // [esp+38h] [ebp-4Ch] BYREF
  vostok::math::float4x4 v18; // [esp+44h] [ebp-40h] BYREF

  y = original_dir->y;
  z = original_dir->z;
  v15 = (float)(target_dir->x * z) - (float)(original_dir->x * target_dir->z);
  v14 = (float)(target_dir->z * y) - (float)(target_dir->y * z);
  v16 = (float)(original_dir->x * target_dir->y) - (float)(target_dir->x * y);
  v5 = fsqrt((float)((float)(v15 * v15) + (float)(v16 * v16)) + (float)(v14 * v14));
  if ( v5 > -1.0 )
  {
    if ( s_bm_current_air_resistance < v5 )
      v5 = s_bm_current_air_resistance;
  }
  else
  {
    v5 = FLOAT_N1_0;
  }
  __libm_sse2_atan2(v12, v13);
  v7 = v5;
  if ( COERCE_FLOAT(LODWORD(v5) & 0x7FFFFFFF) < 0.0000099999997 )
  {
    v10 = vostok::math::float4x4::identity(v6, &v18);
  }
  else
  {
    v8 = (__m128i)LODWORD(s_bm_current_air_resistance);
    *(float *)v8.m128i_i32 = s_bm_current_air_resistance
                           / fsqrt((float)((float)(v15 * v15) + (float)(v16 * v16)) + (float)(v14 * v14));
    v17.x = *(float *)v8.m128i_i32 * v14;
    *(float *)&v9 = *(float *)v8.m128i_i32 * v15;
    *(float *)v8.m128i_i32 = *(float *)v8.m128i_i32 * v16;
    v10 = &v18;
    *(_QWORD *)&v17.elements[1] = __PAIR64__(v8.m128i_u32[0], v9);
    vostok::math::create_rotation(&v17, (int)&v18, v8, COERCE_FLOAT(LODWORD(v7) ^ _mask__NegFloat_));
  }
  qmemcpy(a3, v10, sizeof(vostok::math::float4x4));
  return a3;
}
