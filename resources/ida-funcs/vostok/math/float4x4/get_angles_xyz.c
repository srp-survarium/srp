vostok::math::float3 *__usercall vostok::math::float4x4::get_angles_xyz@<eax>(
        vostok::math::float4x4 *this@<ecx>,
        int a2@<edi>,
        int a3@<esi>)
{
  float v3; // xmm0_4
  double v4; // xmm0_8
  double v5; // xmm0_8
  float v6; // xmm0_4
  double v7; // xmm0_8
  float v8; // xmm0_4
  double v9; // xmm0_8
  long double v11; // [esp+0h] [ebp-10h]
  long double v12; // [esp+0h] [ebp-10h]
  long double v13; // [esp+0h] [ebp-10h]
  long double x; // [esp+8h] [ebp-8h]
  long double xa; // [esp+8h] [ebp-8h]

  HIDWORD(x) = *(_DWORD *)a3;
  v3 = (float)(s_bm_current_air_resistance
             / fsqrt(
                 (float)((float)(*(float *)a3 * *(float *)a3) + (float)(*(float *)(a3 + 4) * *(float *)(a3 + 4)))
               + (float)(*(float *)(a3 + 8) * *(float *)(a3 + 8))))
     * *(float *)(a3 + 8);
  *(float *)&x = v3;
  if ( s_bm_current_air_resistance <= v3 )
  {
    v9 = *(float *)(a3 + 16);
    __libm_sse2_atan2(v11, x);
    *(float *)&v9 = v9;
    *(_DWORD *)a2 = LODWORD(v9);
    v8 = pi_d2_11;
    goto LABEL_6;
  }
  if ( v3 <= -1.0 )
  {
    v7 = *(float *)(a3 + 16);
    __libm_sse2_atan2(v11, x);
    *(float *)&v7 = v7;
    *(_DWORD *)a2 = LODWORD(v7) ^ _mask__NegFloat_;
    v8 = FLOAT_N1_5707964;
LABEL_6:
    *(float *)(a2 + 4) = v8;
    v6 = 0.0;
    goto LABEL_7;
  }
  v4 = COERCE_FLOAT(
         COERCE_UNSIGNED_INT(
           (float)(s_bm_current_air_resistance
                 / fsqrt(
                     (float)((float)(*(float *)(a3 + 24) * *(float *)(a3 + 24))
                           + (float)(*(float *)(a3 + 16) * *(float *)(a3 + 16)))
                   + (float)(*(float *)(a3 + 20) * *(float *)(a3 + 20))))
         * *(float *)(a3 + 24))
       ^ _mask__NegFloat_);
  __libm_sse2_atan2(v11, x);
  *(float *)&v4 = v4;
  *(_DWORD *)a2 = LODWORD(v4);
  __libm_sse2_asin(v12);
  *(_DWORD *)(a2 + 4) = LODWORD(xa);
  v5 = COERCE_FLOAT(*(_DWORD *)(a3 + 4) ^ _mask__NegFloat_);
  __libm_sse2_atan2(v13, xa);
  v6 = v5;
LABEL_7:
  *(float *)(a2 + 8) = v6;
  return (vostok::math::float3 *)a2;
}
