void __thiscall survarium::damage_zone_cook::delete_resource(
        survarium::damage_zone_cook *this,
        vostok::resources::resource_base *resource_base)
{
  unsigned int v3; // ebx
  unsigned int v4; // ebx
  vostok::memory::doug_lea_allocator *v5; // ecx
  const char *v6; // [esp+0h] [ebp-Ch]
  const char *v7; // [esp+4h] [ebp-8h]
  unsigned int v8; // [esp+8h] [ebp-4h]
  vostok::vfs::vfs_hashset *m_hashset; // [esp+14h] [ebp+8h]
  vostok::resources::resource_base::creation_source_enum m_creation_source; // [esp+14h] [ebp+8h]

  v3 = 0;
  m_hashset = resource_base[2].m_fat_it.m_hashset;
  if ( m_hashset )
  {
    do
    {
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(
        (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&resource_base[2].m_fat_it.m_node->m_mount_root.pointer
      + v3);
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(
        (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&resource_base[2].m_fat_it.m_link_target->m_mount_root.pointer
      + v3);
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(4 * v3 + resource_base[2].m_fat_it.m_type));
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(
        (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&resource_base[2].m_name_registry_entry->class_id
      + v3);
      vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy>::dec(
        (vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> *)&resource_base[2].m_next_for_query_finished_callback->$3538424EB7630DF95C3FF114A34636D0::__vftable
      + v3);
      vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy>::dec(
        (vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> *)&resource_base[2].m_next_for_grm_observer_list->__vftable
      + v3++);
    }
    while ( v3 < (unsigned int)m_hashset );
  }
  v4 = 0;
  m_creation_source = resource_base[2].m_creation_source;
  if ( m_creation_source )
  {
    do
    {
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(4 * v4 + resource_base[2].m_construct_thread_id));
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(
        (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)resource_base[2].m_memory_type_data
      + v4);
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(4 * v4 + *((_DWORD *)&resource_base[2].m_memory_type_data + 1)));
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(
        (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&resource_base[3].~vostok::resources::resource_base
      + v4++);
    }
    while ( v4 < m_creation_source );
  }
  ((void (__thiscall *)(vostok::resources::resource_base *, _DWORD))resource_base->~vostok::resources::resource_base)(
    resource_base,
    0);
  vostok::memory::doug_lea_allocator::free_impl(v5, (int)survarium::g_allocator, (char *)resource_base, v6, v7, v8);
}
