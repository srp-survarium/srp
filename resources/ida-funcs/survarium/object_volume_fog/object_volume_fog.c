void __thiscall survarium::object_volume_fog::object_volume_fog(
        survarium::object_volume_fog *this,
        survarium::base_game_scene *w,
        survarium::base_game_scene *s)
{
  float v3; // xmm0_4
  float v4; // eax
  float v5; // [esp+10h] [ebp-8h]
  float v6; // [esp+14h] [ebp-4h]

  survarium::game_object_static::game_object_static(this, w, s);
  v3 = s_bm_current_air_resistance;
  v4 = *(float *)&volume_fog_ids;
  ++volume_fog_ids;
  v5 = s_bm_current_air_resistance;
  v6 = s_bm_current_air_resistance;
  w[1].m_projection_matrix.j.z = s_bm_current_air_resistance;
  w[1].m_projection_matrix.j.w = v5;
  w[1].m_projection_matrix.k.x = v6;
  w[1].m_projection_matrix.j.y = v4;
  *(float *)&w[1].m_mouse_y = v3;
  w[1].m_sound_scene.m_object = 0;
  w->__vftable = (survarium::base_game_scene_vtbl *)&survarium::object_volume_fog::`vftable';
  w[1].m_projection_matrix.k.y = v3;
  w[1].m_projection_matrix.k.z = v3;
  w[1].m_projection_matrix.k.w = v3;
  w[1].m_projection_matrix.c.x = v3;
  w[1].m_projection_matrix.c.y = 0.0;
  w[1].m_projection_matrix.c.z = v3;
  w[1].m_projection_matrix.c.w = 0.0;
  w[1].m_mouse_x = 0;
}
