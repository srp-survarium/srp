vostok::math::float2 *__usercall vostok::math::normalize_safe@<eax>(
        const vostok::math::float2_pod *object@<eax>,
        vostok::math::float2 *result_in_case_of_zero@<edi>,
        vostok::math::float2 *a3@<esi>)
{
  bool v3; // zf
  vostok::math::float2 *result; // eax
  float v5; // xmm0_4
  float y; // [esp+8h] [ebp-14h]
  float x; // [esp+Ch] [ebp-10h]
  float v8; // [esp+14h] [ebp-8h]
  int v9; // [esp+18h] [ebp-4h]

  v8 = fsqrt((float)(object->y * object->y) + (float)(object->x * object->x));
  x = object->x;
  y = object->y;
  if ( COERCE_FLOAT(LODWORD(object->x) & 0x7FFFFFFF) <= COERCE_FLOAT(LODWORD(y) & 0x7FFFFFFF) )
    v9 = LODWORD(object->y) & 0x7FFFFFFF;
  else
    v9 = LODWORD(object->x) & 0x7FFFFFFF;
  v3 = !vostok::math::is_relatively_zero(*(float *)&v9, v8);
  result = a3;
  if ( v3 )
  {
    v5 = (float)(s_bm_current_air_resistance / v8) * y;
    a3->x = (float)(s_bm_current_air_resistance / v8) * x;
    a3->y = v5;
  }
  else
  {
    *a3 = *result_in_case_of_zero;
  }
  return result;
}


vostok::math::float3 *__usercall vostok::math::normalize_safe@<eax>(
        const vostok::math::float3_pod *object@<eax>,
        vostok::math::float3 *result_in_case_of_zero@<edi>,
        vostok::math::float3 *a3@<esi>)
{
  int v3; // xmm0_4
  bool v4; // zf
  vostok::math::float3 *result; // eax
  float v6; // xmm0_4
  float z; // [esp+8h] [ebp-1Ch]
  float y; // [esp+Ch] [ebp-18h]
  float x; // [esp+10h] [ebp-14h]
  float v10; // [esp+1Ch] [ebp-8h]
  int v11; // [esp+20h] [ebp-4h]

  v10 = fsqrt((float)((float)(object->y * object->y) + (float)(object->x * object->x)) + (float)(object->z * object->z));
  z = object->z;
  x = object->x;
  v3 = LODWORD(object->y) & 0x7FFFFFFF;
  y = object->y;
  if ( *(float *)&v3 <= COERCE_FLOAT(LODWORD(z) & 0x7FFFFFFF) )
    v3 = LODWORD(z) & 0x7FFFFFFF;
  if ( COERCE_FLOAT(LODWORD(object->x) & 0x7FFFFFFF) <= *(float *)&v3 )
    v11 = v3;
  else
    v11 = LODWORD(object->x) & 0x7FFFFFFF;
  v4 = !vostok::math::is_relatively_zero(*(float *)&v11, v10);
  result = a3;
  if ( v4 )
  {
    v6 = s_bm_current_air_resistance / v10;
    a3->x = (float)(s_bm_current_air_resistance / v10) * x;
    a3->y = v6 * y;
    a3->z = v6 * z;
  }
  else
  {
    *a3 = *result_in_case_of_zero;
  }
  return result;
}
