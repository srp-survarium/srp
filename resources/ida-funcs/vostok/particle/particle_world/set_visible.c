void __thiscall vostok::particle::particle_world::set_visible(
        vostok::particle::particle_world *this,
        vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> particle_system_instance,
        bool is_visible)
{
  bool v3; // dl
  unsigned int v4; // edi
  unsigned int *p_m_num_lods; // ecx
  vostok::particle::particle_system_instance_impl *m_object; // ebx
  vostok::particle::particle_emitter_instance **p_m_first; // esi
  vostok::particle::particle_emitter_instance *i; // eax

  v3 = is_visible;
  v4 = 0;
  p_m_num_lods = &particle_system_instance.m_object->m_num_lods;
  m_object = particle_system_instance.m_object;
  if ( particle_system_instance.m_object->m_num_lods )
  {
    p_m_first = &particle_system_instance.m_object->m_lods[0].m_emitter_instance_list.m_first;
    do
    {
      for ( i = *p_m_first; i; i = i->m_next )
        i->m_visible = v3;
      ++v4;
      p_m_first += 8;
    }
    while ( v4 < *p_m_num_lods );
  }
  m_object->m_visible = v3;
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&particle_system_instance);
}
