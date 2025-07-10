void __thiscall vostok::particle::particle_system_instance_impl::remove_overflowing_particles(
        vostok::particle::particle_system_instance_impl *this)
{
  vostok::particle::particle_emitter_instance *instance; // [esp+4h] [ebp-4h]
  vostok::particle::particle_emitter_instance *instancea; // [esp+4h] [ebp-4h]

  for ( instance = this->m_lods[this->m_current_lod].m_emitter_instance_list.m_first; instance; instance = instance->m_next )
    instance->remove_overflowing_particles(instance);
  if ( this->m_current_lod != this->m_old_lod )
  {
    for ( instancea = this->m_lods[this->m_old_lod].m_emitter_instance_list.m_first;
          instancea;
          instancea = instancea->m_next )
    {
      instancea->remove_overflowing_particles(instancea);
    }
  }
}
