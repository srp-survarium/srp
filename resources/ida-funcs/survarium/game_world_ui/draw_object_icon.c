char __thiscall survarium::game_world_ui::draw_object_icon(
        survarium::game_world_ui *this,
        int icon_uid,
        const vostok::math::float3 object_position,
        float scalable,
        float ignore_screenspace_check)
{
  survarium::base_game_scene *v5; // eax
  float *m_camera_director; // esi
  survarium::game_world_ui *v7; // ecx
  float v9; // xmm0_4
  char v10; // bl
  char v11; // al
  survarium::game_world_ui *v12; // ecx
  survarium::game_world_ui *v13; // ecx
  vostok::math::float3 v14; // [esp-Ch] [ebp-38h]
  float v15; // [esp+0h] [ebp-2Ch]
  vostok::math::float2 v16; // [esp+1Ch] [ebp-10h] BYREF
  unsigned int v17; // [esp+24h] [ebp-8h]
  float v18; // [esp+28h] [ebp-4h]

  v5 = *(survarium::base_game_scene **)(icon_uid + 20);
  m_camera_director = (float *)v5->m_camera_director;
  v16.x = SNaN;
  v16.y = SNaN;
  if ( survarium::base_game_scene::point_to_screen(&v16, v5, (const vostok::math::float3 *)&object_position.elements[1])
    || LOBYTE(ignore_screenspace_check) )
  {
    survarium::game_world_ui::set_hud_icon_visible(v7, icon_uid, SLOBYTE(object_position.x), 1);
    v9 = (float)(fsqrt(
                   (float)((float)((float)(scalable - m_camera_director[15]) * (float)(scalable - m_camera_director[15]))
                         + (float)((float)(object_position.y - m_camera_director[13])
                                 * (float)(object_position.y - m_camera_director[13])))
                 + (float)((float)(object_position.z - m_camera_director[14])
                         * (float)(object_position.z - m_camera_director[14])))
               - survarium::g_icon_name_near_dist)
       / (float)(survarium::g_icon_name_far_dist - survarium::g_icon_name_near_dist);
    if ( v9 > 0.0 )
    {
      if ( s_bm_current_air_resistance < v9 )
        v9 = s_bm_current_air_resistance;
    }
    else
    {
      v9 = 0.0;
    }
    v10 = survarium::g_icon_name_min_alpha;
    ignore_screenspace_check = s_bm_current_air_resistance - v9;
    v17 = survarium::g_icon_name_max_alpha - survarium::g_icon_name_min_alpha;
    v18 = (float)((float)(survarium::g_icon_name_max_size - survarium::g_icon_name_min_size)
                * (float)(s_bm_current_air_resistance - v9))
        + survarium::g_icon_name_min_size;
    v15 = (double)(survarium::g_icon_name_max_alpha - survarium::g_icon_name_min_alpha)
        * (float)(s_bm_current_air_resistance - v9);
    v11 = vostok::math::floor(v15);
    *(_QWORD *)&v14.x = __PAIR64__(LODWORD(v16.x), LODWORD(object_position.x));
    v14.z = v16.y - (float)(v18 * 5.0);
    LOBYTE(ignore_screenspace_check) = v10 + v11;
    survarium::game_world_ui::set_hud_icon_pos(v12, icon_uid, v14, v18);
    survarium::game_world_ui::set_hud_icon_alpha(
      v13,
      icon_uid,
      LOBYTE(object_position.x),
      LOBYTE(ignore_screenspace_check));
    return 1;
  }
  else
  {
    survarium::game_world_ui::set_hud_icon_visible(v7, icon_uid, SLOBYTE(object_position.x), 0);
    return 0;
  }
}
