const float *__usercall vostok::math::float3_pod::operator[]@<eax>(vostok::math::float3_pod *this@<ecx>, int a2@<eax>)
{
  return (const float *)(a2 + 4 * (_DWORD)this);
}


vostok::math::float3 *__usercall vostok::math::float3_pod::operator-@<eax>(
        vostok::math::float3_pod *this@<ecx>,
        vostok::math::float3 *a2@<eax>)
{
  a2->x = -this->x;
  a2->y = -this->y;
  a2->z = -this->z;
  return a2;
}


vostok::math::float3 *__usercall vostok::math::float3_pod::operator*=@<eax>(
        vostok::math::float3_pod *this@<ecx>,
        vostok::math::float3 *result@<eax>)
{
  result->x = this->x * result->x;
  result->y = this->y * result->y;
  result->z = this->z * result->z;
  return result;
}


float *__usercall vostok::math::float3_pod::operator*=@<eax>(float *result@<eax>, float a2@<xmm0>)
{
  *result = *result * a2;
  result[1] = result[1] * a2;
  result[2] = result[2] * a2;
  return result;
}


vostok::math::float3 *__usercall vostok::math::float3_pod::operator+=@<eax>(
        vostok::math::float3_pod *this@<ecx>,
        vostok::math::float3 *result@<eax>)
{
  result->x = this->x + result->x;
  result->y = this->y + result->y;
  result->z = this->z + result->z;
  return result;
}


vostok::math::float3 *__thiscall vostok::math::float3_pod::operator/=(vostok::math::float3_pod *this, float value)
{
  float v2; // xmm0_4
  vostok::math::float3 *result; // eax
  float v4; // xmm1_4
  float v5; // xmm0_4

  v2 = *(float *)&clear_value / value;
  result = (vostok::math::float3 *)this;
  this->x = this->x * (float)(*(float *)&clear_value / value);
  v4 = v2 * this->y;
  v5 = v2 * this->z;
  this->y = v4;
  this->z = v5;
  return result;
}
