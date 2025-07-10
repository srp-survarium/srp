long double __usercall vostok::math::float3_pod::length@<st0>(vostok::math::float3_pod *this@<ecx>, float *a2@<eax>)
{
  return sqrtf((float)((float)(a2[1] * a2[1]) + (float)(a2[2] * a2[2])) + (float)(*a2 * *a2));
}
