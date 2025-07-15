void __thiscall survarium::generic_anomaly_core::register_artefacts(
        survarium::generic_anomaly_core *this,
        survarium::game_world_core *world,
        int a3)
{
  vostok::resources::resource_ptr<survarium::artefact_base,vostok::resources::unmanaged_intrusive_base> value; // [esp+Ch] [ebp-4h] BYREF
  unsigned int i; // [esp+18h] [ebp+8h]

  for ( i = 0; i < *(_DWORD *)&world->m_game_events_history.m_allocator.m_buffer[332]; ++i )
  {
    vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
      (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&value,
      (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(4 * i + *(_DWORD *)&world->m_game_events_history.m_allocator.m_buffer[328]));
    value.m_object->m_id = (*(_DWORD *)(a3 + 49604) - *(_DWORD *)(a3 + 49600)) >> 2;
    vostok::buffer_vector<vostok::resources::resource_ptr<survarium::artefact_base,vostok::resources::unmanaged_intrusive_base>>::push_back(
      (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&value,
      (vostok::buffer_vector<vostok::resources::resource_ptr<survarium::artefact_base,vostok::resources::unmanaged_intrusive_base> > *)(a3 + 49600));
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&value);
    (*(void (__thiscall **)(_DWORD, int))(**(_DWORD **)(4 * i
                                                      + *(_DWORD *)&world->m_game_events_history.m_allocator.m_buffer[328])
                                        + 92))(
      *(_DWORD *)(4 * i + *(_DWORD *)&world->m_game_events_history.m_allocator.m_buffer[328]),
      a3);
  }
}
