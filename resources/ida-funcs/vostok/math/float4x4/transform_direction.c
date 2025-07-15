vostok::math::float3 *__userpurge vostok::math::float4x4::transform_direction@<eax>(
        const vostok::math::float3 *direction@<edx>,
        vostok::math::float3 *result@<eax>,
        vostok::math::float4x4 *this)
{
  float y; // xmm1_4
  float z; // xmm0_4
  float x; // xmm2_4
  float v6; // xmm4_4

  y = direction->y;
  z = direction->z;
  x = direction->x;
  v6 = this->j.y;
  result->x = (float)((float)(this->j.x * y) + (float)(this->k.x * z)) + (float)(direction->x * this->i.x);
  result->y = (float)((float)(this->i.y * x) + (float)(v6 * y)) + (float)(this->k.y * z);
  result->z = (float)((float)(this->i.z * x) + (float)(this->j.z * y)) + (float)(this->k.z * z);
  return result;
}
