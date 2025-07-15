unsigned int __usercall vostok::render::calculate_wanted_texture_mip_levels@<eax>(
        const vostok::math::float3 *viewer_position@<ecx>,
        const vostok::math::float2 *max_texture_size_calculated_for@<eax>,
        const vostok::math::sphere *object_sphere@<esi>,
        const vostok::math::float4x4 *projection_matrix,
        const unsigned int screen_size_x,
        float screen_size_y,
        float factor,
        float *tiling,
        float *out_distance,
        float *out_wanted_mip_level_decimals)
{
  float x; // xmm1_4
  float v13; // xmm2_4
  float v14; // xmm1_4
  float w; // xmm3_4
  float v16; // xmm0_4
  unsigned int v17; // edi
  float v18; // ecx
  float v19; // xmm2_4
  float v20; // xmm0_4
  float v21; // xmm0_4
  float v22; // xmm0_4
  unsigned int result; // eax
  float v24; // [esp+10h] [ebp-8h]
  int v25; // [esp+14h] [ebp-4h]
  unsigned int v26; // [esp+14h] [ebp-4h]
  float v27; // [esp+2Ch] [ebp+14h]
  float v28; // [esp+2Ch] [ebp+14h]
  float v29; // [esp+30h] [ebp+18h]
  float v30; // [esp+30h] [ebp+18h]
  float v31; // [esp+38h] [ebp+20h]
  float v32; // [esp+38h] [ebp+20h]
  float v33; // [esp+38h] [ebp+20h]

  if ( s_bm_current_air_resistance > factor )
    factor = s_bm_current_air_resistance;
  x = max_texture_size_calculated_for->x;
  v25 = *(_DWORD *)((char *)&loc_88198 + (_DWORD)vostok::quasi_singleton<vostok::render::resource_manager>::pinst);
  if ( max_texture_size_calculated_for->y <= max_texture_size_calculated_for->x )
    x = max_texture_size_calculated_for->y;
  if ( x >= 4.0 )
    v31 = x;
  else
    v31 = FLOAT_4_0;
  v24 = (float)(unsigned __int64)v31;
  vostok::render::fast_log2();
  v13 = viewer_position->z - object_sphere->vector.z;
  v14 = viewer_position->y - object_sphere->vector.y;
  w = object_sphere->vector.w;
  v16 = fsqrt(
          (float)((float)(v13 * v13) + (float)(v14 * v14))
        + (float)((float)(viewer_position->x - object_sphere->vector.x)
                * (float)(viewer_position->x - object_sphere->vector.x)))
      - w;
  v26 = (unsigned __int64)4.0
      - v25
      - 1
      - ((int)((unsigned __int64)4.0 - v25 - 1) < 5 ? (unsigned __int64)4.0 - v25 - 6 : 0);
  *tiling = v16;
  v17 = v26;
  *out_wanted_mip_level_decimals = FLOAT_10000_0;
  if ( v16 > w )
  {
    LODWORD(v18) = 1597463007 - (COERCE_INT((float)(v16 * v16) - (float)(w * w)) >> 1);
    v32 = (float)((float)(vostok::sound::s_lpf_param
                        - (float)((float)((float)((float)((float)(v16 * v16) - (float)(w * w)) * 0.5) * v18) * v18))
                * v18)
        * w;
    v29 = (double)(unsigned int)projection_matrix * v32 * 1.7;
    v19 = screen_size_y;
    v33 = (double)screen_size_x * v32 * 3.1199999;
    if ( screen_size_y <= 0.000099999997 )
      v19 = FLOAT_0_000099999997;
    v20 = v29;
    if ( v29 <= v33 )
      v20 = v33;
    v30 = (float)(v20 / (float)(w * 2.0)) * v19;
    vostok::render::fast_log2();
    v21 = (float)(v24 * factor) - s_bm_current_air_resistance;
    if ( v21 <= s_bm_current_air_resistance )
      v27 = s_bm_current_air_resistance;
    else
      v27 = (float)(v24 * factor) - s_bm_current_air_resistance;
    v17 = (unsigned __int64)v27;
    vostok::render::fast_log2();
    v22 = v21 - s_bm_current_air_resistance;
    if ( v22 <= s_bm_current_air_resistance )
      v28 = s_bm_current_air_resistance;
    else
      v28 = v22;
    *out_wanted_mip_level_decimals = v30;
    *out_distance = v28 - (double)(unsigned __int64)v28;
  }
  result = v26 + ((11 - v26) & ((11 - (unsigned __int64)v26) >> 32));
  if ( v17 <= 5 )
    return 5;
  if ( v17 <= result )
    return v17;
  return result;
}
