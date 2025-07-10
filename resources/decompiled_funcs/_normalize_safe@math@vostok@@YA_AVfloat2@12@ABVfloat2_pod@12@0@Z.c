vostok::math::float2 *__usercall vostok::math::normalize_safe@<eax>(
        const vostok::math::float2_pod *object@<esi>,
        vostok::math::float2 *a2@<edi>,
        vostok::math::float2 *result_in_case_of_zero)
{
  int v3; // xmm0_4
  int v4; // xmm2_4
  float v5; // xmm0_4
  vostok::math::float2 *result; // eax
  float x; // [esp+Ch] [ebp-8h]
  float length; // [esp+10h] [ebp-4h]

  x = object->x;
  length = sqrtf((float)(object->y * object->y) + (float)(object->x * object->x));
  v3 = LODWORD(x) & 0x7FFFFFFF;
  if ( COERCE_FLOAT(LODWORD(x) & 0x7FFFFFFF) <= COERCE_FLOAT(LODWORD(object->y) & 0x7FFFFFFF) )
    v3 = LODWORD(object->y) & 0x7FFFFFFF;
  v4 = v3 & 0x7FFFFFFF;
  if ( COERCE_FLOAT(LODWORD(length) & 0x7FFFFFFF) <= COERCE_FLOAT(v3 & 0x7FFFFFFF)
    && (*(float *)&v4 == 0.0 || (float)(COERCE_FLOAT(LODWORD(length) & 0x7FFFFFFF) / *(float *)&v4) < 0.0000001) )
  {
    result = a2;
    *a2 = *result_in_case_of_zero;
  }
  else
  {
    v5 = (float)(*(float *)&clear_value / length) * object->y;
    a2->x = (float)(*(float *)&clear_value / length) * x;
    a2->y = v5;
    return a2;
  }
  return result;
}
