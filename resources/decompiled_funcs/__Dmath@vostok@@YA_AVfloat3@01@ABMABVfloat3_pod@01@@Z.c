vostok::math::float3 *__usercall vostok::math::operator*@<eax>(
        const vostok::math::float3_pod *right@<ecx>,
        vostok::math::float3 *result@<eax>,
        float *value)
{
  float v3; // xmm0_4

  v3 = *value;
  result->x = *value * right->x;
  result->y = right->y * v3;
  result->z = right->z * v3;
  return result;
}
