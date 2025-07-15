void __usercall survarium::lobby_menu::on_activate(survarium::lobby_menu *this@<ecx>, int a2@<edi>)
{
  int v3; // eax
  survarium::lobby_menu *v4; // ecx
  survarium::lobby_menu *v5; // ecx
  survarium::lobby_menu *v6; // ecx
  vostok::input::world *v7; // eax
  vostok::input::mouse *v8; // ebx
  void (__thiscall **p_set_exclusive_mode)(vostok::input::mouse *, bool); // edi
  bool v10; // al
  survarium::lobby_menu *v11; // ecx

  if ( this->m_timer.m_time_factor == 0.0 )
    vostok::timing::floating_timer::set_time_factor_impl(
      (vostok::timing::floating_timer *)this,
      (int)&this->m_timer,
      this->m_timer.m_backup_time_factor,
      this->m_timer.m_backup_time_floating_factor);
  survarium::base_game_scene::on_activate(this);
  v3 = ((int (__thiscall *)(survarium::game *, int))this->m_game->input_world)(this->m_game, a2);
  (*(void (__thiscall **)(int, vostok::input::handler *))(*(_DWORD *)v3 + 16))(v3, &this->vostok::input::handler);
  if ( survarium::lobby_menu::lobby_client(v4, (int)this)->m_net_client_connected )
    survarium::lobby_menu::query_lobby_info(v5, this);
  survarium::chat_handler::set_mode(
    (const vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&this->m_lobby_menu_ui,
    this->m_game->m_chat_handler,
    0);
  this->m_match_making_match_found = 0;
  survarium::lobby_menu::show_match_making(v6, (int)this, 0);
  v7 = this->m_game->input_world(this->m_game);
  v8 = v7->get_mouse(v7);
  p_set_exclusive_mode = &v8->set_exclusive_mode;
  v10 = this->mouse_exclusive_mode(this);
  (*p_set_exclusive_mode)(v8, v10);
  survarium::lobby_menu::update_play_button_lock(v11, (int)this);
}
