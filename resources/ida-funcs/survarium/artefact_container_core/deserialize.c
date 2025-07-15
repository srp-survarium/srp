void __thiscall survarium::artefact_container_core::deserialize(
        survarium::artefact_container_core *this,
        vostok::network_core::buffer_reader *reader,
        unsigned int time_offset)
{
  vostok::network_core::buffer_reader *v3; // esi
  const unsigned __int8 *m_pointer; // eax
  unsigned int v6; // [esp+0h] [ebp-14h]
  char v7; // [esp+Ch] [ebp-8h]
  unsigned __int8 v8; // [esp+13h] [ebp-1h]

  v3 = reader;
  survarium::usable_object::deserialize_usable_object(
    this,
    this[-1].m_deserialized_users.m_buffer[12].m_store,
    reader,
    v6);
  m_pointer = v3->m_pointer;
  v8 = *m_pointer;
  reader->m_pointer = m_pointer + 1;
  if ( v8 == 0xFF )
  {
    reader = 0;
    v7 = 1;
  }
  else
  {
    v7 = 2;
    vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
      (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&reader,
      (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(*(_DWORD *)(*(_DWORD *)this->m_deserialized_users.m_buffer[0].m_store + 49600) + 4 * v8));
  }
  vostok::resources::resource_ptr<survarium::artefact_base,vostok::resources::unmanaged_intrusive_base>::operator=(
    (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&reader,
    (vostok::resources::resource_ptr<survarium::artefact_base,vostok::resources::unmanaged_intrusive_base> *)&this->m_deserialized_users.m_end);
  if ( (v7 & 2) != 0 )
  {
    v7 &= ~2u;
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&reader);
  }
  if ( (v7 & 1) != 0 )
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&reader);
}
