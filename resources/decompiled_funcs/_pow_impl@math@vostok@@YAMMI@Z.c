float __usercall vostok::math::pow_impl@<xmm0>(unsigned int power@<ecx>, float a2@<xmm1>)
{
  unsigned int v3; // edx
  float result; // xmm0_4
  unsigned int v5; // eax
  unsigned int v6; // ecx

  v3 = 1;
  result = a2;
  if ( power > 1 )
  {
    if ( (int)(power - 1) >= 8 )
    {
      v5 = ((power - 9) >> 3) + 1;
      v3 = 8 * v5 + 1;
      do
      {
        --v5;
        result = (float)((float)((float)((float)((float)((float)((float)(result * a2) * a2) * a2) * a2) * a2) * a2) * a2)
               * a2;
      }
      while ( v5 );
    }
    if ( v3 < power )
    {
      v6 = power - v3;
      do
      {
        --v6;
        result = result * a2;
      }
      while ( v6 );
    }
  }
  return result;
}
