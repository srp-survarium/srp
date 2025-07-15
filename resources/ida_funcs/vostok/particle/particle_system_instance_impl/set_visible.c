void __thiscall vostok::particle::particle_system_instance_impl::set_visible(
        vostok::particle::particle_system_instance_impl *this,
        bool visible)
{
  vostok::particle::particle_emitter_instance *instance; // [esp+4h] [ebp-8h]
  unsigned int i; // [esp+8h] [ebp-4h]

  for ( i = 0; i < this->m_num_lods; ++i )
  {
    for ( instance = this->m_lods[i].m_emitter_instance_list.m_first; instance; instance = instance->m_next )
      vostok::particle::particle_emitter_instance::set_visible(instance, visible);
  }
  this->m_visible = visible;
}
