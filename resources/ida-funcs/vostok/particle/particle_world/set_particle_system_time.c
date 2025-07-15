void __thiscall vostok::particle::particle_world::set_particle_system_time(
        vostok::particle::particle_world *this,
        vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> particle_system_instance,
        float time)
{
  unsigned int v3; // esi
  unsigned int *p_m_num_lods; // ecx
  vostok::particle::particle_emitter_instance **p_m_first; // edx
  vostok::particle::particle_emitter_instance *i; // eax

  v3 = 0;
  p_m_num_lods = &particle_system_instance.m_object->m_num_lods;
  if ( particle_system_instance.m_object->m_num_lods )
  {
    p_m_first = &particle_system_instance.m_object->m_lods[0].m_emitter_instance_list.m_first;
    do
    {
      for ( i = *p_m_first; i; i = i->m_next )
        i->m_emitter_time = time;
      ++v3;
      p_m_first += 8;
    }
    while ( v3 < *p_m_num_lods );
  }
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&particle_system_instance);
}
