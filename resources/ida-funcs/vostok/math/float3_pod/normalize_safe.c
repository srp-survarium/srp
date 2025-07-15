vostok::math::float3 *__thiscall vostok::math::float3_pod::normalize_safe(
        vostok::math::float3_pod *this,
        vostok::math::float3 *result_in_case_of_zero,
        float *a3)
{
  float z; // xmm1_4
  float x; // ecx
  int v6; // xmm0_4
  bool v7; // zf
  vostok::math::float3 *result; // eax
  float v9; // xmm0_4
  float y; // [esp+10h] [ebp-14h]
  float v11; // [esp+14h] [ebp-10h]
  float v12; // [esp+20h] [ebp-4h]
  int v13; // [esp+2Ch] [ebp+8h]

  v12 = fsqrt(
          (float)((float)(result_in_case_of_zero->y * result_in_case_of_zero->y)
                + (float)(result_in_case_of_zero->x * result_in_case_of_zero->x))
        + (float)(result_in_case_of_zero->z * result_in_case_of_zero->z));
  z = result_in_case_of_zero->z;
  x = result_in_case_of_zero->x;
  v11 = result_in_case_of_zero->x;
  v6 = LODWORD(result_in_case_of_zero->y) & 0x7FFFFFFF;
  y = result_in_case_of_zero->y;
  if ( *(float *)&v6 <= COERCE_FLOAT(LODWORD(z) & 0x7FFFFFFF) )
    v6 = LODWORD(z) & 0x7FFFFFFF;
  if ( COERCE_FLOAT(LODWORD(x) & 0x7FFFFFFF) <= *(float *)&v6 )
    v13 = v6;
  else
    v13 = LODWORD(x) & 0x7FFFFFFF;
  v7 = !vostok::math::is_relatively_zero(*(float *)&v13, v12);
  result = result_in_case_of_zero;
  if ( v7 )
  {
    v9 = s_bm_current_air_resistance / v12;
    result_in_case_of_zero->x = v11 * (float)(s_bm_current_air_resistance / v12);
    result_in_case_of_zero->y = y * v9;
    result_in_case_of_zero->z = z * v9;
  }
  else
  {
    result_in_case_of_zero->x = *a3;
    result_in_case_of_zero->y = a3[1];
    result_in_case_of_zero->z = a3[2];
  }
  return result;
}
