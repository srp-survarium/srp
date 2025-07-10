vostok::math::float3 *__usercall vostok::math::float3_pod::operator*=@<eax>(
        vostok::math::float3_pod *this@<ecx>,
        vostok::math::float3 *result@<eax>)
{
  result->x = this->x * result->x;
  result->y = this->y * result->y;
  result->z = this->z * result->z;
  return result;
}
