vostok::math::float3 *__usercall vostok::math::float4x4::get_scale@<eax>(
        vostok::math::float4x4 *this@<ecx>,
        vostok::math::float3 *a2@<eax>)
{
  float v2; // xmm3_4
  float z; // xmm2_4
  float v4; // xmm0_4
  float v5; // xmm3_4
  float x; // xmm2_4

  v2 = (float)(this->j.z * this->j.z) + (float)(this->j.x * this->j.x);
  z = this->k.z;
  a2->x = fsqrt((float)((float)(this->i.z * this->i.z) + (float)(this->i.x * this->i.x)) + (float)(this->i.y * this->i.y));
  v4 = fsqrt(v2 + (float)(this->j.y * this->j.y));
  v5 = z * z;
  x = this->k.x;
  a2->y = v4;
  a2->z = fsqrt((float)(v5 + (float)(x * x)) + (float)(this->k.y * this->k.y));
  return a2;
}
