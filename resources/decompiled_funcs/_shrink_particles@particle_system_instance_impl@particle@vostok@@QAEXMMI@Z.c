void __thiscall vostok::particle::particle_system_instance_impl::shrink_particles(
        vostok::particle::particle_system_instance_impl *this,
        float time_delta,
        float limit_over_total,
        unsigned int num_need_particles)
{
  vostok::particle::particle_emitter_instance *i; // [esp+10h] [ebp-8h]
  vostok::particle::particle_emitter_instance *instance; // [esp+14h] [ebp-4h]

  for ( instance = this->m_lods[this->m_current_lod].m_emitter_instance_list.m_first; instance; instance = instance->m_next )
    ((void (__thiscall *)(vostok::particle::particle_emitter_instance *, _DWORD, _DWORD, unsigned int))instance->shrink_particles)(
      instance,
      LODWORD(time_delta),
      LODWORD(limit_over_total),
      num_need_particles);
  if ( this->m_current_lod != this->m_old_lod )
  {
    for ( i = this->m_lods[this->m_old_lod].m_emitter_instance_list.m_first; i; i = i->m_next )
      ((void (__thiscall *)(vostok::particle::particle_emitter_instance *, _DWORD, _DWORD, unsigned int))i->shrink_particles)(
        i,
        LODWORD(time_delta),
        LODWORD(limit_over_total),
        num_need_particles);
  }
}
