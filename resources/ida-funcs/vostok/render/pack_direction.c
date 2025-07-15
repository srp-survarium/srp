int __usercall vostok::render::pack_direction@<eax>(const vostok::math::float3 *value@<eax>, int a2@<ecx>)
{
  float v2; // xmm0_4
  float v3; // xmm2_4
  int v4; // ecx
  float v5; // xmm2_4
  int v6; // ecx
  float v7; // xmm2_4
  int v9; // [esp+0h] [ebp-4h]

  HIBYTE(v9) = HIBYTE(a2);
  v2 = s_bm_current_air_resistance;
  v3 = (float)(value->x + s_bm_current_air_resistance) * 0.5;
  if ( v3 > 0.0 )
  {
    if ( s_bm_current_air_resistance < v3 )
      v3 = s_bm_current_air_resistance;
  }
  else
  {
    v3 = 0.0;
  }
  v4 = (int)(float)(v3 * 255.0);
  v5 = (float)(value->y + s_bm_current_air_resistance) * 0.5;
  LOBYTE(v9) = v4;
  if ( v5 > 0.0 )
  {
    if ( s_bm_current_air_resistance < v5 )
      v5 = s_bm_current_air_resistance;
  }
  else
  {
    v5 = 0.0;
  }
  v6 = (int)(float)(v5 * 255.0);
  v7 = (float)(value->z + s_bm_current_air_resistance) * 0.5;
  BYTE1(v9) = v6;
  if ( v7 > 0.0 )
  {
    if ( s_bm_current_air_resistance >= v7 )
      v2 = (float)(value->z + s_bm_current_air_resistance) * 0.5;
  }
  else
  {
    v2 = 0.0;
  }
  BYTE2(v9) = (int)(float)(v2 * 255.0);
  return v9;
}
