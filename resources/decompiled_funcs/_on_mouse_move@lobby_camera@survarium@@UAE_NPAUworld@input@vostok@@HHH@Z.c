char __thiscall survarium::lobby_camera::on_mouse_move(
        survarium::lobby_camera *this,
        vostok::input::world *input_world,
        int x,
        int y,
        int z)
{
  vostok::engine_user::engine *m_engine; // ecx
  float v8; // xmm0_4
  vostok::math::float2 render_window_size; // [esp+4h] [ebp-8h] BYREF

  if ( !this->m_game_scene->is_mouse_over_ui(this->m_game_scene) )
    this->m_z_mouse_axis = this->m_z_mouse_axis - (float)((float)z * 0.001);
  if ( !this->m_capture_move )
    return 0;
  m_engine = this->m_game_scene->m_game->m_engine;
  m_engine->get_render_window_size(m_engine, &render_window_size);
  v8 = this->m_rotation_delta.y
     - (float)((float)((float)((float)(render_window_size.y / render_window_size.x)
                             * (float)(survarium::g_mouse_sensitivity * 0.1))
                     * 0.95492965)
             * (float)((float)((float)y * 0.0055555557) * 3.1415927));
  this->m_rotation_delta.x = this->m_rotation_delta.x
                           - (float)((float)((float)((float)x * 0.0055555557) * 3.1415927)
                                   * (float)(survarium::g_mouse_sensitivity * 0.1));
  this->m_rotation_delta.y = v8;
  return 1;
}
