void __thiscall survarium::network_client::unload(survarium::network_client *this)
{
  survarium::game_statistics_handler *v2; // ecx
  vostok::particle::particle_system_instance_impl *m_object; // ecx
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v4; // [esp+Ch] [ebp-4h] BYREF

  if ( !vostok::command_line::key::is_set((vostok::command_line::key *)this, (int)&s_disable_game_statistics_gathering) )
    survarium::game_statistics_handler::clear(v2, (int)&this->m_game_statistics);
  vostok::resources::resource_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base>::operator=(
    &this->m_current_player,
    0);
  vostok::resources::resource_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base>::operator=(
    &this->m_local_player,
    0);
  vostok::resources::resource_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base>::operator=(
    &this->m_last_current_player,
    0);
  m_object = (vostok::particle::particle_system_instance_impl *)this->m_match.m_object;
  this->m_match.m_object = 0;
  v4.m_object = m_object;
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v4);
}
