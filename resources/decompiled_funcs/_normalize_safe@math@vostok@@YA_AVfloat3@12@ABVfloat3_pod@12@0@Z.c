vostok::math::float3 *__usercall vostok::math::normalize_safe@<eax>(
        const vostok::math::float3_pod *object@<esi>,
        vostok::math::float3 *a2@<edi>,
        vostok::math::float3 *result_in_case_of_zero)
{
  float z; // xmm1_4
  float y; // xmm2_4
  float v5; // xmm5_4
  int v6; // xmm0_4
  int v7; // xmm4_4
  float v8; // xmm0_4
  vostok::math::float3 *result; // eax
  float x; // [esp+Ch] [ebp-Ch]
  int v11; // [esp+Ch] [ebp-Ch]
  float length; // [esp+14h] [ebp-4h]

  x = object->x;
  length = sqrtf((float)((float)(object->y * object->y) + (float)(object->x * object->x)) + (float)(object->z * object->z));
  z = object->z;
  y = object->y;
  v5 = x;
  v6 = LODWORD(y) & 0x7FFFFFFF;
  v11 = LODWORD(x) & 0x7FFFFFFF;
  if ( COERCE_FLOAT(LODWORD(y) & 0x7FFFFFFF) <= COERCE_FLOAT(LODWORD(z) & 0x7FFFFFFF) )
    v6 = LODWORD(object->z) & 0x7FFFFFFF;
  if ( *(float *)&v11 > *(float *)&v6 )
    v6 = v11;
  v7 = v6 & 0x7FFFFFFF;
  if ( COERCE_FLOAT(LODWORD(length) & 0x7FFFFFFF) <= COERCE_FLOAT(v6 & 0x7FFFFFFF)
    && (*(float *)&v7 == 0.0 || (float)(COERCE_FLOAT(LODWORD(length) & 0x7FFFFFFF) / *(float *)&v7) < 0.0000001) )
  {
    result = a2;
    *a2 = *result_in_case_of_zero;
  }
  else
  {
    v8 = *(float *)&clear_value / length;
    a2->x = (float)(*(float *)&clear_value / length) * v5;
    a2->y = v8 * y;
    a2->z = v8 * z;
    return a2;
  }
  return result;
}
