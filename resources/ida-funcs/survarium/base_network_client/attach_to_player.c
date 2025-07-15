void __thiscall survarium::base_network_client::attach_to_player(
        survarium::base_network_client *this,
        vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> player)
{
  survarium::game *m_game; // esi
  vostok::particle::particle_system_instance_impl *m_object; // eax
  survarium::stats_graph *m_linear_speed_graph; // edx
  survarium::player_input_handler *m_input_handler; // ecx
  vostok::particle::particle_system_instance_impl *v7; // ecx
  survarium::game *v8; // ecx
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v9; // [esp-4h] [ebp-10h] BYREF

  this->detach_from_player(this);
  this->m_input_handler->m_game_toggle_actions.m_end = this->m_input_handler->m_game_toggle_actions.m_begin;
  this->m_input_handler->m_is_enabled = 1;
  vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base>::operator=(
    &player,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&this->m_current_player);
  vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base>::operator=(
    &player,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&this->m_last_current_player);
  m_game = this->m_game;
  m_object = player.m_object;
  m_linear_speed_graph = this->m_linear_speed_graph;
  m_input_handler = this->m_input_handler;
  *(_DWORD *)((char *)&loc_11403 + (unsigned int)player.m_object + 5) = m_input_handler;
  *(vostok::particle::particle_system_instance_impl_vtbl **)((char *)&m_object->__vftable + (_DWORD)&loc_1140A + 2) = (vostok::particle::particle_system_instance_impl_vtbl *)m_linear_speed_graph;
  *(int *)((char *)&dword_1141C + (_DWORD)m_object) = (int)&m_game->m_game_world.game_ui;
  *(_DWORD *)(*(int *)((char *)&dword_11410 + (_DWORD)m_object) + 13616) = m_input_handler;
  survarium::player::set_effect_presenter(
    (survarium::player *)m_input_handler,
    (int)player.m_object,
    &this->m_game->m_game_world.m_first_person_game_effect_presenter);
  if ( this->m_is_spectator )
  {
    v9.m_object = v7;
    vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
      &v9,
      &player);
    survarium::game::draw_player_name(
      v8,
      (vostok::resources::resource_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base>)this->m_game,
      v9);
  }
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&player);
}
