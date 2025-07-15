vostok::physics *__usercall vostok::physics::get_capsule_random_surface_point@<eax>(
        vostok::math::random32 *a1@<eax>,
        long double a2@<esi:edi>,
        float a3@<xmm0>,
        vostok::physics *this,
        struct vostok::math::float3 *retstr)
{
  __m128i v7; // xmm0
  float v8; // xmm0_4
  float v9; // xmm0_4
  float v12; // [esp+24h] [ebp-4h]
  float v13; // [esp+30h] [ebp+8h]
  float v14; // [esp+30h] [ebp+8h]
  float v15; // [esp+34h] [ebp+Ch]
  float v16; // [esp+34h] [ebp+Ch]

  v15 = vostok::math::random32::random_f(
          a1,
          0.0,
          (float)((float)(a3 * *(float *)&retstr) * 12.566371) + (float)((float)(a3 * a3) * 12.566371));
  *(_DWORD *)this = 0;
  *((_DWORD *)this + 1) = 0;
  *((_DWORD *)this + 2) = 0;
  if ( (float)((float)(a3 * a3) * 12.566371) <= v15 )
  {
    v14 = vostok::math::random32::random_f(a1, 1.0) * 6.2831855;
    *((float *)this + 1) = vostok::math::random32::random_f(a1, 1.0) - 0.5;
    *(float *)this = cos(v14);
    *((float *)this + 2) = sin(v14);
  }
  else
  {
    v13 = vostok::math::random32::random_f(a1, 2.0) - s_bm_current_air_resistance;
    v7 = (__m128i)LODWORD(v13);
    v16 = vostok::math::random32::random_f(a1, 6.2831855);
    v12 = fsqrt(s_bm_current_air_resistance - (float)(*(float *)v7.m128i_i32 * *(float *)v7.m128i_i32));
    __libm_sse2_cos(a2);
    *(double *)v7.m128i_i64 = v16;
    __libm_sse2_sin(v7);
    v8 = v16 * v12;
    if ( (float)(v16 * v12) >= 0.0 )
      v9 = v8 + 0.5;
    else
      v9 = v8 - 0.5;
    *(float *)this = v16 * v12;
    *((float *)this + 1) = v9;
    *((float *)this + 2) = v13;
  }
  return this;
}
