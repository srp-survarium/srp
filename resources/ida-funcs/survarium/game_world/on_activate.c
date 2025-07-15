void __thiscall survarium::game_world::on_activate(survarium::game_world *this)
{
  vostok::input::handler *v2; // edi
  vostok::input::world *v3; // eax
  vostok::sound::world_user *v4; // eax
  vostok::input::world *v5; // ebx
  vostok::input::world *v6; // ebp
  void (__thiscall **p_add_handler)(vostok::input::world *, int); // edi
  int v8; // eax
  vostok::input::world *v9; // eax
  vostok::input::mouse *v10; // ebx
  void (__thiscall **p_set_exclusive_mode)(vostok::input::mouse *, bool); // edi
  bool v12; // al

  survarium::base_game_scene::on_activate(this);
  if ( this )
    v2 = &this->vostok::input::handler;
  else
    v2 = 0;
  v3 = this->m_game->input_world(this->m_game);
  v3->add_handler(v3, v2);
  v4 = this->m_game->m_sound_world->get_logic_world_user(this->m_game->m_sound_world);
  vostok::sound::world_user::set_active_sound_scene(&this->m_sound_scene, v4);
  if ( this->m_game->m_network_client->has_bandwidth(this->m_game->m_network_client) )
    survarium::chat_handler::set_mode(
      (const vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&this->game_ui.m_game_hud_ui,
      this->m_game->m_chat_handler,
      1);
  if ( vostok::core::journal_usage() == record_journal )
  {
    v5 = this->m_game->input_world(this->m_game);
    v6 = this->m_game->input_world(this->m_game);
    p_add_handler = (void (__thiscall **)(vostok::input::world *, int))&v6->add_handler;
    v8 = (int)v5->get_journaling_handler(v5);
    (*p_add_handler)(v6, v8);
  }
  v9 = this->m_game->input_world(this->m_game);
  v10 = v9->get_mouse(v9);
  p_set_exclusive_mode = &v10->set_exclusive_mode;
  v12 = this->mouse_exclusive_mode(this);
  (*p_set_exclusive_mode)(v10, v12);
}
