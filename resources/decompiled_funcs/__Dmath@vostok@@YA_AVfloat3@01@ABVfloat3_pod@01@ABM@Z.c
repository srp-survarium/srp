vostok::math::float3 *__usercall vostok::math::operator*@<eax>(
        const vostok::math::float3_pod *left@<ecx>,
        vostok::math::float3 *result@<eax>,
        float *value)
{
  float v3; // xmm0_4

  v3 = *value;
  result->x = left->x * *value;
  result->y = left->y * v3;
  result->z = left->z * v3;
  return result;
}
