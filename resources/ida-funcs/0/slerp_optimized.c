vostok::math::quaternion *__usercall slerp_optimized@<eax>(
        const vostok::math::quaternion *q0@<ecx>,
        const vostok::math::quaternion *q1@<eax>,
        vostok::math::quaternion *t,
        float a4)
{
  float z; // xmm5_4
  __m128 y_low; // xmm6
  float v6; // xmm2_4
  float y; // xmm1_4
  float w; // xmm4_4
  float v9; // xmm3_4
  __m128 v10; // xmm0
  float v11; // xmm7_4
  __m128i v12; // xmm0
  float v13; // xmm1_4
  __m128 v14; // xmm0
  __m128i v15; // xmm0
  float v16; // xmm0_4
  float v17; // xmm0_4
  vostok::math::quaternion *result; // eax
  float v19; // [esp+10h] [ebp-50h]
  float v20; // [esp+18h] [ebp-48h]
  float x; // [esp+1Ch] [ebp-44h]
  float v22; // [esp+20h] [ebp-40h]
  float v23; // [esp+20h] [ebp-40h]
  float v24; // [esp+24h] [ebp-3Ch]
  float v25; // [esp+28h] [ebp-38h]
  float v26; // [esp+2Ch] [ebp-34h]

  z = q1->z;
  y_low = (__m128)LODWORD(q1->y);
  v6 = q0->z;
  y = q0->y;
  w = q1->w;
  v9 = q0->w;
  x = q0->x;
  v20 = q1->x;
  v10 = y_low;
  v10.m128_f32[0] = (float)((float)((float)(y_low.m128_f32[0] * y) + (float)(z * v6)) + (float)(w * v9))
                  + (float)(q1->x * q0->x);
  v26 = y;
  v25 = q1->y;
  if ( v10.m128_f32[0] >= 0.0 )
  {
    v11 = FLOAT_1_0;
  }
  else
  {
    v10 = _mm_xor_ps(v10, (__m128)_mask__NegFloat_);
    v11 = FLOAT_N1_0;
  }
  if ( v10.m128_f32[0] >= 0.99998999 )
  {
    v23 = 1.0 - a4;
    v16 = a4;
  }
  else
  {
    v12 = (__m128i)_mm_cvtps_pd(v10);
    __libm_sse2_acos();
    *(float *)v12.m128i_i32 = *(double *)v12.m128i_i64;
    v22 = *(float *)v12.m128i_i32;
    *(double *)v12.m128i_i64 = *(float *)v12.m128i_i32;
    __libm_sse2_sin(v12);
    v13 = *(double *)v12.m128i_i64;
    v19 = 1.0 / v13;
    v14 = (__m128)LODWORD(v22);
    v14.m128_f32[0] = v22 - (float)(v22 * a4);
    v24 = v22 * a4;
    v15 = (__m128i)_mm_cvtps_pd(v14);
    __libm_sse2_sin(v15);
    *(float *)v15.m128i_i32 = *(double *)v15.m128i_i64;
    v23 = *(float *)v15.m128i_i32 * (float)(1.0 / v13);
    *(double *)v15.m128i_i64 = v24;
    __libm_sse2_sin(v15);
    y_low.m128_f32[0] = v25;
    y = v26;
    v16 = v24 * v19;
  }
  v17 = v16 * v11;
  result = t;
  t->x = (float)(x * v23) + (float)(v20 * v17);
  t->y = (float)(y * v23) + (float)(y_low.m128_f32[0] * v17);
  t->z = (float)(v6 * v23) + (float)(z * v17);
  t->w = (float)(v9 * v23) + (float)(w * v17);
  return result;
}
