void __thiscall vostok::particle::particle_system_instance_impl::reset(
        vostok::particle::particle_system_instance_impl *this)
{
  vostok::particle::particle_emitter_instance *instance; // [esp+4h] [ebp-Ch]
  unsigned int i; // [esp+Ch] [ebp-4h]

  for ( i = 0; i < this->m_num_lods; ++i )
  {
    for ( instance = this->m_lods[i].m_emitter_instance_list.m_first; instance; instance = instance->m_next )
      vostok::particle::particle_emitter_instance::reset(instance);
  }
}
