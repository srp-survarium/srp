float __userpurge vostok::math::float3_pod::normalize_safe_r@<xmm0>(
        vostok::math::float3_pod *this@<ecx>,
        float *a2@<eax>,
        const vostok::math::float3_pod *result_in_case_of_zero)
{
  int v4; // xmm0_4
  float v5; // xmm0_4
  float v7; // [esp+Ch] [ebp-1Ch]
  float v8; // [esp+10h] [ebp-18h]
  float v9; // [esp+14h] [ebp-14h]
  int v10; // [esp+20h] [ebp-8h]
  float v11; // [esp+24h] [ebp-4h]

  v11 = fsqrt((float)((float)(a2[1] * a2[1]) + (float)(*a2 * *a2)) + (float)(a2[2] * a2[2]));
  v7 = a2[2];
  v9 = *a2;
  v4 = (_DWORD)a2[1] & 0x7FFFFFFF;
  v8 = a2[1];
  if ( *(float *)&v4 <= COERCE_FLOAT(LODWORD(v7) & 0x7FFFFFFF) )
    v4 = (_DWORD)a2[2] & 0x7FFFFFFF;
  if ( COERCE_FLOAT(*(_DWORD *)a2 & 0x7FFFFFFF) <= *(float *)&v4 )
    v10 = v4;
  else
    v10 = *(_DWORD *)a2 & 0x7FFFFFFF;
  if ( vostok::math::is_relatively_zero(*(float *)&v10, v11) )
  {
    *(vostok::math::float3_pod *)a2 = *result_in_case_of_zero;
  }
  else
  {
    v5 = s_bm_current_air_resistance / v11;
    *a2 = v9 * (float)(s_bm_current_air_resistance / v11);
    a2[1] = v8 * v5;
    a2[2] = v7 * v5;
  }
  return v11;
}
