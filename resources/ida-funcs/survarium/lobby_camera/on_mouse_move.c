char __thiscall survarium::lobby_camera::on_mouse_move(
        survarium::lobby_camera *this,
        vostok::input::world *input_world,
        int x,
        int y,
        int z)
{
  vostok::input::mouse *v6; // eax
  survarium::lobby_camera *v7; // ecx
  vostok::engine_user::engine *m_engine; // ecx
  float v10; // xmm3_4
  float v11; // xmm0_4
  int v12; // [esp-4h] [ebp-10h]
  float v13[2]; // [esp+4h] [ebp-8h] BYREF

  if ( !this->m_game_scene->is_mouse_over_ui(this->m_game_scene) )
    this->m_z_mouse_axis = this->m_z_mouse_axis - (float)((float)z * 0.001);
  v6 = input_world->get_mouse(input_world);
  if ( (*(_BYTE *)(v6->get_state(v6) + 12) & 0x52) != 0 )
  {
    if ( this->m_capture_move )
      goto LABEL_10;
    survarium::lobby_camera::capture_mouse(v7, (int)this, 1);
  }
  else
  {
    if ( !this->m_capture_move )
      return 0;
    v12 = this->m_capture_point.y;
    this->m_capture_move = 0;
    SetCursorPos(this->m_capture_point.x, v12);
  }
  if ( !this->m_capture_move )
    return 0;
LABEL_10:
  m_engine = this->m_game_scene->m_game->m_engine;
  m_engine->get_render_window_size(m_engine, (vostok::math::float2 *)v13);
  v10 = (float)((float)((float)(v13[1] / v13[0]) * (float)(survarium::g_mouse_sensitivity * 0.1)) * 0.95492965)
      * (float)((float)((float)y * 0.0055555557) * 3.1415927);
  v11 = this->m_rotation_delta.y;
  this->m_rotation_delta.x = this->m_rotation_delta.x
                           - (float)((float)((float)((float)x * 0.0055555557) * 3.1415927)
                                   * (float)(survarium::g_mouse_sensitivity * 0.1));
  this->m_rotation_delta.y = v11 - v10;
  return 1;
}
