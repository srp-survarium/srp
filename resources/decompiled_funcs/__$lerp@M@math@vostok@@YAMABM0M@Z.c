float __usercall vostok::math::lerp<float>@<xmm0>(const float *current@<eax>, const float *target@<ecx>, float amount)
{
  return (float)((float)(*target - *current) * amount) + *current;
}
