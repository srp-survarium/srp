void __userpurge survarium::damage_zone_core::effect_intensity(
        survarium::damage_zone_core *this@<ecx>,
        int a2@<esi>,
        const survarium::base_player *player)
{
  const vostok::math::float4x4 *v3; // eax
  survarium::collision_geometry *v4; // ecx
  float v5; // xmm1_4
  unsigned int v6; // ebx
  const vostok::math::float3 *v7; // edi
  float v8; // xmm0_4
  float v9; // xmm0_4
  vostok::math::curve_line_points<float,0> *v10; // ecx
  float v11; // [esp+20h] [ebp-4h]

  v3 = player->transform(&player->survarium::collision_user);
  v5 = s_bm_current_air_resistance;
  v6 = 0;
  v7 = (const vostok::math::float3 *)&v3->lines[3];
  v11 = s_bm_current_air_resistance;
  if ( !*(_DWORD *)(a2 + 288) )
    goto LABEL_7;
  do
  {
    v8 = survarium::collision_geometry::relative_distance_to(
           v4,
           *(const vostok::math::float3 **)(*(_DWORD *)(a2 + 284) + 4 * v6),
           v7);
    v5 = v11;
    if ( v11 > v8 )
    {
      v5 = v8;
      v11 = v8;
    }
    ++v6;
  }
  while ( v6 < *(_DWORD *)(a2 + 288) );
  v9 = 0.0;
  if ( v5 <= 0.0 || (v9 = s_bm_current_air_resistance, s_bm_current_air_resistance < v5) )
    vostok::math::curve_line_points<float,0>::evaluate(
      (vostok::math::curve_line_points<float,0> *)v4,
      a2 + 360,
      v9,
      0.0,
      range_time_type,
      0.0,
      0.0);
  else
LABEL_7:
    vostok::math::curve_line_points<float,0>::evaluate(
      (vostok::math::curve_line_points<float,0> *)v4,
      a2 + 360,
      v5,
      0.0,
      range_time_type,
      0.0,
      0.0);
  vostok::math::curve_line_points<float,0>::evaluate(
    v10,
    a2 + 392,
    player->m_linear_horizontal_speed,
    1.0,
    range_time_type,
    0.0,
    0.0);
}
