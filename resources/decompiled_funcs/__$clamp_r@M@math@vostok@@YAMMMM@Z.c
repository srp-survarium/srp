__m128 __usercall vostok::math::clamp_r<float>@<xmm0>(__m128 result@<xmm0>, __int128 a2@<xmm1>, float max)
{
  if ( result.m128_f32[0] < *(float *)&a2 )
  {
    result = (__m128)LODWORD(max);
    if ( max >= *(float *)&a2 )
      return (__m128)a2;
  }
  return result;
}
