void __usercall vostok::render::potential_request::calc_priority(
        vostok::render::potential_request *this@<ecx>,
        int a2@<eax>)
{
  float v2; // xmm2_4
  float v3; // xmm1_4
  float v4; // xmm2_4
  float v5; // xmm3_4
  float v6; // xmm1_4
  float v7; // [esp+0h] [ebp-8h]
  float v8; // [esp+4h] [ebp-4h]

  v2 = *(float *)(a2 + 56);
  if ( s_bm_current_air_resistance < v2 )
  {
    v3 = s_spot_max_distance;
    if ( s_spot_max_distance >= v2 )
      v3 = *(float *)(a2 + 56);
  }
  else
  {
    v3 = s_bm_current_air_resistance;
  }
  v4 = s_bm_current_air_resistance - fsqrt(v3 * 0.0099999998);
  v5 = *(float *)(a2 + 100);
  if ( s_bm_current_air_resistance < v5 )
  {
    v6 = FLOAT_300_0;
    if ( v5 <= 300.0 )
      v6 = *(float *)(a2 + 100);
  }
  else
  {
    v6 = s_bm_current_air_resistance;
  }
  v8 = (double)*(unsigned int *)(a2 + 12) * 0.090909094;
  v7 = (double)*(unsigned int *)(a2 + 72) * 0.2;
  *(float *)(a2 + 92) = (float)((float)((float)((float)(v6 * 0.0016666667) + s_bm_current_air_resistance) * v8)
                              + (float)(v7 * 5.0))
                      + v4;
}
