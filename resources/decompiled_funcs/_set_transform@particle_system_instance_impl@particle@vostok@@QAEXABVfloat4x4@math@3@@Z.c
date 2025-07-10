void __thiscall vostok::particle::particle_system_instance_impl::set_transform(
        vostok::particle::particle_system_instance_impl *this,
        const vostok::math::float4x4 *transform)
{
  vostok::particle::particle_emitter_instance *instance; // [esp+Ch] [ebp-8h]
  unsigned int i; // [esp+10h] [ebp-4h]

  qmemcpy((void *)&this->m_transform, transform, sizeof(this->m_transform));
  for ( i = 0; i < this->m_num_lods; ++i )
  {
    for ( instance = this->m_lods[i].m_emitter_instance_list.m_first; instance; instance = instance->m_next )
      vostok::particle::particle_emitter_instance::set_transform(instance, transform);
  }
}
