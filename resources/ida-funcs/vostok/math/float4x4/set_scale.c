void __thiscall vostok::math::float4x4::set_scale(vostok::math::float4x4 *this, const vostok::math::float3 *scale)
{
  float v2; // xmm1_4
  float x; // xmm0_4
  float v4; // xmm1_4
  float v5; // xmm0_4
  float v6; // xmm1_4

  v2 = scale->x
     / fsqrt((float)((float)(this->i.x * this->i.x) + (float)(this->i.y * this->i.y)) + (float)(this->i.z * this->i.z));
  this->i.x = this->i.x * v2;
  this->i.y = v2 * this->i.y;
  this->i.z = this->i.z * v2;
  x = this->j.x;
  v4 = scale->y / fsqrt((float)((float)(x * x) + (float)(this->j.y * this->j.y)) + (float)(this->j.z * this->j.z));
  this->j.x = x * v4;
  this->j.y = v4 * this->j.y;
  this->j.z = this->j.z * v4;
  v5 = this->k.x;
  v6 = scale->z / fsqrt((float)((float)(this->k.y * this->k.y) + (float)(this->k.z * this->k.z)) + (float)(v5 * v5));
  this->k.x = v5 * v6;
  this->k.y = this->k.y * v6;
  this->k.z = this->k.z * v6;
}
