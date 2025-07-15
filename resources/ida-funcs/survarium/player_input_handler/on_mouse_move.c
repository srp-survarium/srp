bool __thiscall survarium::player_input_handler::on_mouse_move(
        survarium::player_input_handler *this,
        vostok::input::world *input_world,
        int x,
        int y,
        survarium::toggle_action_enum z)
{
  float v6; // xmm0_4
  vostok::journaling::journal_usage_enum v7; // eax
  float m_fov_factor; // xmm0_4
  float v9; // xmm0_4
  float v10; // xmm0_4
  vostok::engine_user::engine *m_engine; // esi
  float *p_y; // ebx
  float *v13; // eax
  survarium::action_state_enum binded_action; // eax
  survarium::player_input_handler *v15; // ecx
  survarium::game_action_id v16; // esi
  vostok::math::float2 v18; // [esp+Ch] [ebp-1Ch] BYREF
  vostok::math::float2 v19; // [esp+14h] [ebp-14h] BYREF
  stlp_std::pair<enum survarium::game_action_id,enum survarium::action_state_enum> item; // [esp+1Ch] [ebp-Ch] BYREF
  float v21; // [esp+24h] [ebp-4h]

  if ( survarium::g_mouse_invert )
    v6 = FLOAT_N1_0;
  else
    v6 = s_bm_current_air_resistance;
  *(float *)&item.second = v6;
  v7 = vostok::core::journal_usage();
  m_fov_factor = this->m_fov_factor;
  if ( v7 == replay_journal )
    v9 = m_fov_factor * g_journaling_mouse_sensitivity.x;
  else
    v9 = (float)(m_fov_factor * survarium::g_mouse_sensitivity) * 0.1;
  v21 = v9;
  if ( vostok::core::journal_usage() == replay_journal )
  {
    v10 = this->m_fov_factor * g_journaling_mouse_sensitivity.y;
  }
  else
  {
    m_engine = this->m_game_world->m_game->m_engine;
    p_y = &m_engine->get_render_window_size(m_engine, &v19)->y;
    v13 = (float *)m_engine->get_render_window_size(m_engine, &v18);
    v10 = (float)((float)((float)(*p_y / *v13) * v21) * *(float *)&item.second) * 0.95492965;
  }
  this->m_current_input.rotation_delta.x = this->m_current_input.rotation_delta.x
                                         - (float)((float)((float)((float)x * 0.0055555557) * 3.1415927) * v21);
  this->m_current_input.rotation_delta.y = this->m_current_input.rotation_delta.y
                                         - (float)((float)((float)((float)y * 0.0055555557) * 3.1415927) * v10);
  this->m_z_mouse_axis = this->m_z_mouse_axis - (float)((float)z * 0.001);
  if ( z )
  {
    binded_action = survarium::key_binder::get_binded_action(
                      this->m_game_world->m_game->m_key_binder,
                      (z <= hold_action) + 345,
                      &z,
                      1);
    v16 = binded_action;
    if ( binded_action != 73 )
    {
      survarium::player_input_handler::process_dependent_actions(
        v15,
        (const survarium::game_action_id)this,
        binded_action,
        0);
      item.first = v16;
      item.second = action_down;
      vostok::circular_buffer<stlp_std::pair<enum survarium::game_action_id,enum survarium::action_state_enum>,64>::push_back(
        &this->m_game_actions,
        &item);
    }
  }
  return 0;
}
