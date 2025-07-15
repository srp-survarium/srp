void __userpurge vostok::particle::particle_system_instance_impl::set_transform(
        const vostok::math::float4x4 *transform@<eax>,
        vostok::particle::particle_system_instance_impl *this,
        const vostok::math::float4x4 *second_transform)
{
  bool v3; // zf
  int v4; // ecx
  vostok::particle::particle_emitter_instance **p_m_first; // edi
  vostok::particle::particle_emitter_instance *i; // esi
  unsigned int v7; // [esp+Ch] [ebp-4h]

  v7 = 0;
  v3 = this->m_num_lods == 0;
  qmemcpy(&this->m_transform, transform, sizeof(this->m_transform));
  qmemcpy(&this->m_second_transform, second_transform, sizeof(this->m_second_transform));
  v4 = 0;
  if ( !v3 )
  {
    p_m_first = &this->m_lods[0].m_emitter_instance_list.m_first;
    do
    {
      for ( i = *p_m_first; i; i = i->m_next )
        vostok::particle::particle_emitter_instance::set_transform(v4, &this->m_transform, i, &this->m_second_transform);
      ++v7;
      p_m_first += 8;
    }
    while ( v7 < this->m_num_lods );
  }
}
