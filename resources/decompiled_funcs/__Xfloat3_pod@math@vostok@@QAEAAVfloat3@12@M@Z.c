float *__usercall vostok::math::float3_pod::operator*=@<eax>(float *result@<eax>, float a2@<xmm0>)
{
  *result = *result * a2;
  result[1] = result[1] * a2;
  result[2] = result[2] * a2;
  return result;
}
