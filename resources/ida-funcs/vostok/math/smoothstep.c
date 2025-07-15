float __usercall vostok::math::smoothstep@<xmm0>(float a1@<xmm0>, float a2@<xmm1>, vostok::math *this)
{
  float v3; // xmm0_4
  float v4; // xmm1_4

  v3 = (float)(a1 - *(float *)&this) / (float)(a2 - *(float *)&this);
  v4 = 0.0;
  if ( v3 > 0.0 )
  {
    v4 = s_bm_current_air_resistance;
    if ( s_bm_current_air_resistance >= v3 )
      v4 = v3;
  }
  return (float)((float)(3.0 - (float)(v4 * 2.0)) * v4) * v4;
}
