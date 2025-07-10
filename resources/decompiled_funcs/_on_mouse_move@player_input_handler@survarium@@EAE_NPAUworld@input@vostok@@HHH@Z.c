bool __thiscall survarium::player_input_handler::on_mouse_move(
        survarium::player_input_handler *this,
        vostok::input::world *input_world,
        int x,
        int y,
        int z)
{
  vostok::engine_user::engine *m_engine; // esi
  float *p_y; // ebx
  float v8; // xmm0_4
  float m_z_mouse_axis; // xmm1_4
  float horizontal_sensitivity; // [esp+Ch] [ebp-14h]
  vostok::math::float2 v12; // [esp+10h] [ebp-10h] BYREF
  vostok::math::float2 v13; // [esp+18h] [ebp-8h] BYREF

  m_engine = this->m_game_world->m_game->m_engine;
  horizontal_sensitivity = (float)(this->m_fov_factor * survarium::g_mouse_sensitivity) * 0.1;
  p_y = &m_engine->get_render_window_size(m_engine, &v12)->y;
  v8 = (float)((float)(*p_y / m_engine->get_render_window_size(m_engine, &v13)->x) * horizontal_sensitivity)
     * 0.95492965;
  if ( survarium::g_mouse_invert )
    v8 = -v8;
  this->m_rotation_delta.x = this->m_rotation_delta.x
                           - (float)((float)((float)((float)x * 0.0055555557) * 3.1415927) * horizontal_sensitivity);
  m_z_mouse_axis = this->m_z_mouse_axis;
  this->m_rotation_delta.y = this->m_rotation_delta.y
                           - (float)((float)((float)((float)y * 0.0055555557) * 3.1415927) * v8);
  this->m_z_mouse_axis = m_z_mouse_axis - (float)((float)z * 0.001);
  return 0;
}
