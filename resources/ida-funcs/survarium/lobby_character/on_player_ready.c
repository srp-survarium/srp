void __thiscall survarium::lobby_character::on_player_ready(
        survarium::lobby_character *this,
        vostok::resources::queries_result *data)
{
  int m_current_profile_idx; // eax
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *p_m_unmanaged_resource; // edi
  vostok::resources::queries_result *m_object; // esi
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v6; // [esp+18h] [ebp-4h] BYREF

  survarium::lobby_character::clear_resources(
    this,
    (vostok::resources::resource_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base> *)this);
  m_current_profile_idx = this->m_current_profile_idx;
  this->m_current_query_id = -1;
  p_m_unmanaged_resource = &data->m_queries[0].m_unmanaged_resource;
  this->m_current_profile_idx = (m_current_profile_idx + 1) % 3;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    &v6,
    (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)p_m_unmanaged_resource);
  m_object = (vostok::resources::queries_result *)v6.m_object;
  data = 0;
  if ( v6.m_object )
  {
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data);
    data = m_object;
    _InterlockedExchangeAdd((volatile signed __int32 *)&m_object->m_queries[0].m_target_quality_level, 1u);
  }
  vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base>::operator=(
    (const vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&data,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&this->m_player);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v6);
  ((void (__stdcall *)(_DWORD, _DWORD, _DWORD, _DWORD))this->m_player.m_object->initialize)(
    this->m_lobby_menu->m_current_time_in_ms,
    &this->m_position,
    this->m_orientation,
    0.0);
  this->m_player.m_object->insert(this->m_player.m_object, 1);
  if ( this->m_need_to_requery )
  {
    this->m_need_to_requery = 0;
    survarium::lobby_character::setup_profile(this, &this->m_profiles[(this->m_current_profile_idx + 1) % 3]);
  }
}
