vostok::math::float3 *__userpurge vostok::math::float4x4::transform_position@<eax>(
        const vostok::math::float3 *vector@<edx>,
        vostok::math::float3 *result@<eax>,
        vostok::math::float4x4 *this)
{
  float y; // xmm1_4
  float z; // xmm0_4
  float x; // xmm2_4
  float v6; // xmm4_4

  y = vector->y;
  z = vector->z;
  x = vector->x;
  v6 = this->j.y;
  result->x = (float)((float)((float)(this->j.x * y) + (float)(this->k.x * z)) + (float)(vector->x * this->i.x))
            + this->c.x;
  result->y = (float)((float)((float)(this->i.y * x) + (float)(v6 * y)) + (float)(this->k.y * z)) + this->c.y;
  result->z = (float)((float)((float)(this->i.z * x) + (float)(this->j.z * y)) + (float)(this->k.z * z)) + this->c.z;
  return result;
}
