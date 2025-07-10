vostok::math::float4 *__thiscall vostok::math::float4x4::transform(
        vostok::math::float4x4 *this,
        vostok::math::float4 *result,
        const vostok::math::float4 *vector)
{
  float z; // xmm1_4
  float y; // xmm2_4
  float w; // xmm0_4
  float x; // xmm3_4
  vostok::math::float4 *v7; // eax
  float v8; // xmm5_4
  float v9; // xmm4_4
  float v10; // xmm5_4

  z = vector->z;
  y = vector->y;
  w = vector->w;
  x = vector->x;
  v7 = result;
  v8 = this->j.y;
  result->x = (float)((float)((float)(this->j.x * y) + (float)(this->k.x * z)) + (float)(this->c.x * w))
            + (float)(vector->x * this->i.x);
  v9 = (float)((float)((float)(this->i.y * x) + (float)(v8 * y)) + (float)(this->k.y * z)) + (float)(this->c.y * w);
  v10 = this->j.z;
  result->y = v9;
  result->z = (float)((float)((float)(this->i.z * x) + (float)(v10 * y)) + (float)(this->k.z * z))
            + (float)(this->c.z * w);
  result->w = (float)((float)((float)(this->i.w * x) + (float)(this->j.w * y)) + (float)(this->k.w * z))
            + (float)(this->c.w * w);
  return v7;
}
