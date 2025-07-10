vostok::math::float3 *__usercall vostok::math::normalize@<eax>(
        const vostok::math::float3_pod *object@<esi>,
        float *a2@<edi>)
{
  float v2; // xmm0_4
  float length; // [esp+4h] [ebp-8h]
  float x; // [esp+8h] [ebp-4h]

  x = object->x;
  length = sqrtf((float)((float)(object->x * object->x) + (float)(object->y * object->y)) + (float)(object->z * object->z));
  v2 = *(float *)&clear_value / length;
  *a2 = (float)(*(float *)&clear_value / length) * x;
  a2[1] = v2 * object->y;
  a2[2] = object->z * v2;
  return (vostok::math::float3 *)a2;
}
