void __usercall vostok::math::clamp<float>(float *value_and_result@<eax>, float a2@<xmm1>, float max)
{
  float v4; // xmm0_4

  v4 = *value_and_result;
  if ( a2 >= *value_and_result || (a2 = max, max < v4) )
    v4 = a2;
  *value_and_result = v4;
}
