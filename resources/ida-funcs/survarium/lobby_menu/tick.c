void __thiscall survarium::lobby_menu::tick(
        survarium::lobby_menu *this,
        const unsigned int __formal,
        const unsigned int a3,
        bool is_game_paused)
{
  survarium::flash_movie *elapsed_msec; // ebx
  unsigned int m_current_time_in_ms; // ecx
  unsigned int v7; // esi
  survarium::lobby_menu *v8; // ecx
  survarium::lobby_client *v9; // eax
  survarium::lobby_client *v10; // ecx
  vostok::math::half *v11; // ecx
  survarium::lobby_character *v12; // ecx
  survarium::lobby_character *v13; // ecx
  survarium::lobby_character *v14; // ecx
  vostok::ui::world *v15; // eax
  survarium::stats *m_stats; // esi
  int v17; // eax
  int v18; // eax
  survarium::game_effect_player *v19; // ecx
  survarium::game_effect_player *v20; // ecx
  const vostok::math::float3 *v21; // [esp+0h] [ebp-Ch]
  unsigned int v22; // [esp+0h] [ebp-Ch]
  unsigned int v23; // [esp+0h] [ebp-Ch]
  unsigned int v24; // [esp+0h] [ebp-Ch]
  int __formala; // [esp+1Ch] [ebp+10h]

  elapsed_msec = (survarium::flash_movie *)vostok::timing::floating_timer::get_elapsed_msec(
                                             (vostok::timing::floating_timer *)this,
                                             &this->m_timer);
  m_current_time_in_ms = this->m_current_time_in_ms;
  if ( (unsigned int)elapsed_msec > m_current_time_in_ms )
  {
    v7 = (unsigned int)elapsed_msec - m_current_time_in_ms;
    this->m_current_time_in_ms = (unsigned int)elapsed_msec;
    survarium::base_game_scene::tick(
      this,
      (unsigned int)elapsed_msec - m_current_time_in_ms,
      (unsigned int)elapsed_msec,
      is_game_paused);
    if ( (unsigned int)elapsed_msec - this->m_last_ping_time_in_ms >= 0x3E8 )
    {
      v9 = survarium::lobby_menu::lobby_client(v8, (int)this);
      survarium::lobby_client::ping_server(v10, (int)v9);
      this->m_last_ping_time_in_ms = (unsigned int)elapsed_msec;
    }
    survarium::camera_director::apply((survarium::camera_director *)v8, this->m_camera_director);
    if ( this->m_is_ui_shown )
      survarium::lobby_menu::update_ui(this, v7, elapsed_msec);
    this->m_game->m_sound_world->get_logic_world_user(this->m_game->m_sound_world);
    vostok::sound::world_user::set_listener_properties_interlocked(
      &this->m_sound_scene,
      v11,
      (vostok::math::float3 *)&this->m_inverted_view_matrix.lines[3],
      (const vostok::math::float3 *)&this->m_inverted_view_matrix.lines[2],
      (const vostok::math::float3 *)&this->m_inverted_view_matrix.lines[1],
      v21);
    survarium::lobby_character::update(v12, (int)this->m_character, (unsigned int)elapsed_msec, v22);
    survarium::lobby_character::update(v13, (int)this->m_squad_member[0], (unsigned int)elapsed_msec, v23);
    survarium::lobby_character::update(v14, (int)this->m_squad_member[1], (unsigned int)elapsed_msec, v24);
    v15 = this->m_game->ui_world(this->m_game);
    m_stats = this->m_game->m_stats;
    __formala = (int)v15->get_renderer(v15);
    m_stats->m_main_window->draw(
      m_stats->m_main_window,
      (vostok::render::ui::renderer *)__formala,
      &this->m_render_scene_view);
    v17 = (int)m_stats->m_dispersion_components->w(m_stats->m_dispersion_components);
    (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v17 + 16))(v17, 0);
    v18 = (int)m_stats->m_recoil_components->w(m_stats->m_recoil_components);
    (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v18 + 16))(v18, 0);
    survarium::game_effect_player::tick(v19, &this->m_effect_player.m_current_time_in_ms, (unsigned int)elapsed_msec);
    survarium::game_effect_player::present(v20, (int)&this->m_effect_player, &this->m_effect_presenter, 0);
  }
}
