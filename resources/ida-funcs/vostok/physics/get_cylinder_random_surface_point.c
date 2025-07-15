vostok::math::float3 *__usercall vostok::physics::get_cylinder_random_surface_point@<eax>(
        vostok::buffer_vector<float> *a1@<ecx>,
        float *a2@<edi>,
        int a3@<esi>,
        vostok::math::random32 *result)
{
  vostok::buffer_vector<float> *v4; // ecx
  vostok::buffer_vector<float> *v5; // ecx
  float *v6; // eax
  float v7; // xmm0_4
  float v8; // xmm1_4
  float v9; // xmm2_4
  __m128i v10; // xmm0
  int v11; // eax
  double v12; // st7
  float v13; // xmm0_4
  long double v15; // [esp+4h] [ebp-34h]
  float *v16; // [esp+Ch] [ebp-2Ch] BYREF
  float *v17; // [esp+10h] [ebp-28h]
  float *v18; // [esp+14h] [ebp-24h]
  _BYTE v19[24]; // [esp+18h] [ebp-20h] BYREF
  float v20; // [esp+30h] [ebp-8h] BYREF
  float v21; // [esp+34h] [ebp-4h] BYREF

  v16 = (float *)v19;
  v17 = (float *)v19;
  LODWORD(v15) = a3;
  v18 = &v20;
  v20 = pi_23;
  vostok::buffer_vector<float>::push_back(a1, (int)&v16, &v20);
  v20 = *v16 + 3.1415927;
  vostok::buffer_vector<float>::push_back(v4, (int)&v16, &v20);
  v20 = v16[1] + 3.1415927;
  vostok::buffer_vector<float>::push_back(v5, (int)&v16, &v20);
  v21 = vostok::math::random32::random_f(result, 9.424778);
  v6 = stlp_std::lower_bound<float *,float,stlp_std::less<float>>(v16, v17, &v21);
  if ( v6 == v16 )
    v7 = 0.0;
  else
    v7 = *(v6 - 1);
  v8 = v21 - v7;
  v9 = *v6 - v7;
  v10 = (__m128i)LODWORD(pi_x2_13);
  v11 = v6 - v16;
  v21 = 6.2831855 - (float)((float)(v8 / v9) * 6.2831855);
  if ( v11 >= 0 )
  {
    if ( v11 <= 1 )
    {
      if ( v11 )
        v13 = FLOAT_N0_5;
      else
        v13 = c_anim_center;
      a2[1] = v13;
      v20 = vostok::math::random32::random_f(result, 2.0) - s_bm_current_air_resistance;
      v10 = (__m128i)LODWORD(v20);
      v20 = fsqrt(s_bm_current_air_resistance - (float)(*(float *)v10.m128i_i32 * *(float *)v10.m128i_i32));
      *(double *)v10.m128i_i64 = v21;
      __libm_sse2_cos(v15);
      *(float *)v10.m128i_i32 = *(double *)v10.m128i_i64;
      *a2 = *(float *)v10.m128i_i32 * v20;
      *(double *)v10.m128i_i64 = v21;
      __libm_sse2_sin(v10);
      *(float *)v10.m128i_i32 = *(double *)v10.m128i_i64;
      *(float *)v10.m128i_i32 = *(float *)v10.m128i_i32 * v20;
      goto LABEL_12;
    }
    if ( v11 == 2 )
    {
      v12 = vostok::math::random32::random_f(result, 1.0);
      *(double *)v10.m128i_i64 = v21;
      a2[1] = v12 - 0.5;
      __libm_sse2_cos(v15);
      *(float *)v10.m128i_i32 = *(double *)v10.m128i_i64;
      *a2 = *(float *)v10.m128i_i32;
      *(double *)v10.m128i_i64 = v21;
      __libm_sse2_sin(v10);
      *(float *)v10.m128i_i32 = *(double *)v10.m128i_i64;
LABEL_12:
      a2[2] = *(float *)v10.m128i_i32;
    }
  }
  return (vostok::math::float3 *)a2;
}
