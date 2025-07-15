vostok::math::float4x4 *__fastcall vostok::math::create_rotation(
        const vostok::math::float3 *normal,
        const vostok::math::float3 *direction,
        int a3)
{
  float z; // xmm0_4
  float y; // xmm6_4
  vostok::math::float4x4 *result; // eax
  float v6; // xmm3_4
  float x; // xmm1_4
  float v8; // xmm4_4
  float v9; // xmm0_4
  float v10; // xmm5_4
  float v11; // xmm2_4
  float v12; // xmm3_4
  float v13; // xmm4_4
  float v14; // xmm4_4
  float v15; // [esp+4h] [ebp-20h]
  float v16; // [esp+Ch] [ebp-18h]
  float v17; // [esp+10h] [ebp-14h]

  z = direction->z;
  y = direction->y;
  result = (vostok::math::float4x4 *)a3;
  v6 = (float)(normal->y * z) - (float)(normal->z * y);
  x = normal->x;
  v8 = (float)(direction->x * normal->z) - (float)(normal->x * z);
  v9 = (float)(normal->x * y) - (float)(direction->x * normal->y);
  v10 = s_bm_current_air_resistance / fsqrt((float)((float)(v9 * v9) + (float)(v6 * v6)) + (float)(v8 * v8));
  v11 = v10 * v6;
  v15 = v10 * v6;
  v12 = v10 * v8;
  v13 = normal->y;
  *(float *)a3 = v15;
  *(float *)(a3 + 4) = v12;
  *(float *)(a3 + 8) = v9 * v10;
  *(_DWORD *)(a3 + 12) = 0;
  v16 = normal->z;
  *(float *)(a3 + 16) = x;
  *(float *)(a3 + 20) = v13;
  v14 = normal->y;
  *(float *)(a3 + 24) = v16;
  *(_DWORD *)(a3 + 28) = 0;
  *(float *)(a3 + 32) = (float)(v16 * v12) - (float)(v14 * (float)(v9 * v10));
  *(float *)(a3 + 36) = (float)(x * (float)(v9 * v10)) - (float)(v16 * v11);
  *(float *)(a3 + 40) = (float)(v14 * v11) - (float)(x * v12);
  *(_DWORD *)(a3 + 44) = 0;
  v17 = s_bm_current_air_resistance;
  *(_DWORD *)(a3 + 48) = 0;
  *(_DWORD *)(a3 + 52) = 0;
  *(_DWORD *)(a3 + 56) = 0;
  *(float *)(a3 + 60) = v17;
  return result;
}


vostok::math::float4x4 *__usercall vostok::math::create_rotation@<eax>(
        const vostok::math::float3 *angles@<eax>,
        int a2@<edi>,
        int a3)
{
  __m128i v4; // xmm0
  __m128i v5; // xmm0
  __m128i v6; // xmm0
  long double v8; // [esp-4h] [ebp-40h]
  long double v9; // [esp-4h] [ebp-40h]
  long double v10; // [esp-4h] [ebp-40h]
  float x; // [esp+10h] [ebp-2Ch]
  float y; // [esp+10h] [ebp-2Ch]
  float z; // [esp+10h] [ebp-2Ch]
  float v14; // [esp+14h] [ebp-28h]
  float v15; // [esp+18h] [ebp-24h]
  float v16; // [esp+1Ch] [ebp-20h]
  float v17; // [esp+20h] [ebp-1Ch]
  float v18; // [esp+38h] [ebp-4h]

  x = angles->x;
  LODWORD(v8) = a2;
  v4 = (__m128i)_mm_cvtps_pd((__m128)LODWORD(angles->x));
  __libm_sse2_sin(v4);
  *(float *)v4.m128i_i32 = *(double *)v4.m128i_i64;
  v14 = *(float *)v4.m128i_i32;
  __libm_sse2_cos(v8);
  v15 = x;
  y = angles->y;
  v5 = (__m128i)_mm_cvtps_pd((__m128)LODWORD(y));
  __libm_sse2_sin(v5);
  *(float *)v5.m128i_i32 = *(double *)v5.m128i_i64;
  v16 = *(float *)v5.m128i_i32;
  __libm_sse2_cos(v9);
  v17 = y;
  z = angles->z;
  v6 = (__m128i)_mm_cvtps_pd((__m128)LODWORD(z));
  __libm_sse2_sin(v6);
  *(float *)v6.m128i_i32 = *(double *)v6.m128i_i64;
  __libm_sse2_cos(v10);
  *(float *)a3 = z * v17;
  *(_DWORD *)(a3 + 4) = COERCE_UNSIGNED_INT(*(float *)v6.m128i_i32 * v17) ^ _mask__NegFloat_;
  *(float *)(a3 + 8) = v16;
  *(_DWORD *)(a3 + 12) = 0;
  *(float *)(a3 + 16) = (float)(*(float *)v6.m128i_i32 * v15) + (float)(v16 * (float)(z * v14));
  *(float *)(a3 + 20) = (float)(z * v15) - (float)((float)(v16 * *(float *)v6.m128i_i32) * v14);
  *(_DWORD *)(a3 + 24) = COERCE_UNSIGNED_INT(v17 * v14) ^ _mask__NegFloat_;
  *(_DWORD *)(a3 + 28) = 0;
  *(float *)(a3 + 32) = (float)(*(float *)v6.m128i_i32 * v14) - (float)((float)(v16 * z) * v15);
  *(float *)(a3 + 36) = (float)((float)(v16 * *(float *)v6.m128i_i32) * v15) + (float)(z * v14);
  *(float *)(a3 + 40) = v15 * v17;
  *(_DWORD *)(a3 + 44) = 0;
  v18 = s_bm_current_air_resistance;
  *(_DWORD *)(a3 + 48) = 0;
  *(_DWORD *)(a3 + 52) = 0;
  *(_DWORD *)(a3 + 56) = 0;
  *(float *)(a3 + 60) = v18;
  return (vostok::math::float4x4 *)a3;
}


vostok::math::float4x4 *__usercall vostok::math::create_rotation@<eax>(
        const vostok::math::float3 *axis@<edi>,
        int a2@<esi>,
        __m128i a3@<xmm0>,
        float angle)
{
  float y; // xmm3_4
  float z; // xmm4_4
  float v6; // xmm2_4
  float v7; // xmm7_4
  float v8; // xmm4_4
  float v9; // xmm1_4
  float v10; // xmm6_4
  float v11; // xmm7_4
  float v12; // xmm5_4
  long double v14; // [esp+0h] [ebp-14h]
  float v15; // [esp+0h] [ebp-14h]
  float v16; // [esp+8h] [ebp-Ch]

  *(double *)a3.m128i_i64 = angle;
  __libm_sse2_sin(a3);
  *(float *)&v14 = angle;
  __libm_sse2_cos(v14);
  y = axis->y;
  z = axis->z;
  v6 = s_bm_current_air_resistance;
  v16 = z * z;
  v7 = z * y;
  v8 = z * v15;
  v9 = (float)(axis->z * axis->x) * (float)(s_bm_current_air_resistance - angle);
  v10 = (float)(y * axis->x) * (float)(s_bm_current_air_resistance - angle);
  v11 = v7 * (float)(s_bm_current_air_resistance - angle);
  v12 = axis->x * v15;
  *(float *)a2 = (float)((float)(s_bm_current_air_resistance - (float)(axis->x * axis->x)) * angle)
               + (float)(axis->x * axis->x);
  *(float *)(a2 + 4) = v10 - v8;
  *(float *)(a2 + 8) = (float)(y * v15) + v9;
  *(_DWORD *)(a2 + 12) = 0;
  *(float *)(a2 + 20) = (float)((float)(v6 - (float)(y * y)) * angle) + (float)(y * y);
  *(_DWORD *)(a2 + 28) = 0;
  *(float *)(a2 + 24) = v11 - v12;
  *(float *)(a2 + 16) = v8 + v10;
  *(float *)(a2 + 32) = v9 - (float)(y * v15);
  *(float *)(a2 + 40) = (float)((float)(v6 - v16) * angle) + v16;
  *(_DWORD *)(a2 + 44) = 0;
  *(float *)(a2 + 36) = v12 + v11;
  *(_DWORD *)(a2 + 48) = 0;
  *(_DWORD *)(a2 + 52) = 0;
  *(_DWORD *)(a2 + 56) = 0;
  *(float *)(a2 + 60) = v6;
  return (vostok::math::float4x4 *)a2;
}


vostok::math::float4x4 *__usercall vostok::math::create_rotation@<eax>(
        const vostok::math::float3 *angles@<eax>,
        int a2@<edi>,
        const vostok::math::axis_rotation_order order)
{
  __m128i v4; // xmm0
  __m128i v5; // xmm0
  __m128i v6; // xmm0
  long double v8; // [esp-4h] [ebp-40h]
  long double v9; // [esp-4h] [ebp-40h]
  long double v10; // [esp-4h] [ebp-40h]
  float x; // [esp+10h] [ebp-2Ch]
  float y; // [esp+10h] [ebp-2Ch]
  float z; // [esp+10h] [ebp-2Ch]
  float v14; // [esp+14h] [ebp-28h]
  float v15; // [esp+18h] [ebp-24h]
  float v16; // [esp+1Ch] [ebp-20h]
  float v17; // [esp+20h] [ebp-1Ch]
  float v18; // [esp+38h] [ebp-4h]

  x = angles->x;
  LODWORD(v8) = a2;
  v4 = (__m128i)_mm_cvtps_pd((__m128)LODWORD(angles->x));
  __libm_sse2_sin(v4);
  *(float *)v4.m128i_i32 = *(double *)v4.m128i_i64;
  v14 = *(float *)v4.m128i_i32;
  __libm_sse2_cos(v8);
  v15 = x;
  y = angles->y;
  v5 = (__m128i)_mm_cvtps_pd((__m128)LODWORD(y));
  __libm_sse2_sin(v5);
  *(float *)v5.m128i_i32 = *(double *)v5.m128i_i64;
  v16 = *(float *)v5.m128i_i32;
  __libm_sse2_cos(v9);
  v17 = y;
  z = angles->z;
  v6 = (__m128i)_mm_cvtps_pd((__m128)LODWORD(z));
  __libm_sse2_sin(v6);
  *(float *)v6.m128i_i32 = *(double *)v6.m128i_i64;
  __libm_sse2_cos(v10);
  *(float *)order = (float)(v17 * z) - (float)(v14 * (float)(*(float *)v6.m128i_i32 * v16));
  *(_DWORD *)(order + 4) = COERCE_UNSIGNED_INT(v15 * *(float *)v6.m128i_i32) ^ _mask__NegFloat_;
  *(float *)(order + 8) = (float)(v14 * (float)(v17 * *(float *)v6.m128i_i32)) + (float)(z * v16);
  *(_DWORD *)(order + 12) = 0;
  *(float *)(order + 16) = (float)(v14 * (float)(z * v16)) + (float)(v17 * *(float *)v6.m128i_i32);
  *(float *)(order + 20) = v15 * z;
  *(float *)(order + 24) = (float)(*(float *)v6.m128i_i32 * v16) - (float)(v14 * (float)(v17 * z));
  *(_DWORD *)(order + 28) = 0;
  *(_DWORD *)(order + 32) = COERCE_UNSIGNED_INT(v15 * v16) ^ _mask__NegFloat_;
  *(float *)(order + 36) = v14;
  *(float *)(order + 40) = v15 * v17;
  *(_DWORD *)(order + 44) = 0;
  v18 = s_bm_current_air_resistance;
  *(_DWORD *)(order + 48) = 0;
  *(_DWORD *)(order + 52) = 0;
  *(_DWORD *)(order + 56) = 0;
  *(float *)(order + 60) = v18;
  return (vostok::math::float4x4 *)order;
}
