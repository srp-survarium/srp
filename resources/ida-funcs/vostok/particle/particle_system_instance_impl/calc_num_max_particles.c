unsigned int __thiscall vostok::particle::particle_system_instance_impl::calc_num_max_particles(
        vostok::particle::particle_system_instance_impl *this,
        float time_delta)
{
  unsigned int total_summ; // [esp+8h] [ebp-8h]
  vostok::particle::particle_emitter_instance *instance; // [esp+Ch] [ebp-4h]
  vostok::particle::particle_emitter_instance *instancea; // [esp+Ch] [ebp-4h]

  if ( this->m_paused )
    return 0;
  total_summ = 0;
  for ( instance = this->m_lods[this->m_current_lod].m_emitter_instance_list.m_first; instance; instance = instance->m_next )
    total_summ += ((int (__thiscall *)(vostok::particle::particle_emitter_instance *, _DWORD))instance->calc_num_max_particles)(
                    instance,
                    LODWORD(time_delta));
  if ( this->m_current_lod != this->m_old_lod )
  {
    for ( instancea = this->m_lods[this->m_old_lod].m_emitter_instance_list.m_first;
          instancea;
          instancea = instancea->m_next )
    {
      total_summ += ((int (__thiscall *)(vostok::particle::particle_emitter_instance *, _DWORD))instancea->calc_num_max_particles)(
                      instancea,
                      LODWORD(time_delta));
    }
  }
  return total_summ;
}
