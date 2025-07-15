bool __userpurge vostok::math::quaternion::get_axis_and_angle@<al>(
        vostok::math::quaternion *this@<ecx>,
        float *a2@<eax>,
        int a3@<ebx>,
        long double a4@<esi:edi>,
        vostok::math::float3 *axis,
        float *angle)
{
  float v6; // xmm0_4
  float v7; // xmm1_4
  float v8; // xmm2_4
  float v9; // xmm0_4
  bool result; // al
  long double v11; // [esp-4h] [ebp-10h]
  __int64 v12; // [esp+4h] [ebp-8h]

  v6 = *a2;
  LODWORD(v11) = a3;
  v7 = s_bm_current_air_resistance;
  v8 = fsqrt((float)((float)(v6 * v6) + (float)(a2[1] * a2[1])) + (float)(a2[2] * a2[2]));
  if ( v8 <= 0.0000001 )
  {
    v9 = 0.0;
    *(_QWORD *)&this->x = 0;
    this->z = v7;
    result = 0;
  }
  else
  {
    *((float *)&v11 + 1) = v6 * (float)(s_bm_current_air_resistance / v8);
    *(float *)&v12 = (float)(s_bm_current_air_resistance / v8) * a2[1];
    *((float *)&v12 + 1) = a2[2] * (float)(s_bm_current_air_resistance / v8);
    this->x = *((float *)&v11 + 1);
    *(_QWORD *)&this->vector.elements[1] = v12;
    __libm_sse2_atan2(a4, v11);
    v9 = v8 * 2.0;
    result = 1;
  }
  axis->x = v9;
  return result;
}
