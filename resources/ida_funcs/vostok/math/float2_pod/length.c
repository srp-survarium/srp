long double __usercall vostok::math::float2_pod::length@<st0>(vostok::math::float2_pod *this@<ecx>, float *a2@<eax>)
{
  return sqrtf((float)(a2[1] * a2[1]) + (float)(*a2 * *a2));
}
