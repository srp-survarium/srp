void __thiscall vostok::particle::particle_emitter_instance::play_child(
        vostok::particle::particle_emitter_instance *this,
        vostok::particle::particle_event *evt,
        const vostok::math::float4x4 *transform)
{
  vostok::particle::particle_emitter_instance *instance; // [esp+20h] [ebp-20h]
  vostok::particle::particle_emitter *v5; // [esp+24h] [ebp-1Ch]
  unsigned int k; // [esp+28h] [ebp-18h]
  unsigned int j; // [esp+2Ch] [ebp-14h]
  vostok::particle::particle_emitter *emitter; // [esp+30h] [ebp-10h]
  unsigned int i; // [esp+34h] [ebp-Ch]
  unsigned int lod_index; // [esp+38h] [ebp-8h]
  bool found_emitter; // [esp+3Fh] [ebp-1h]

  found_emitter = 0;
  for ( lod_index = 0; !lod_index; lod_index = 1 )
  {
    for ( i = 0; i < this->m_emitter->m_particle_system.pointer->m_lods.pointer->m_num_emitters; ++i )
    {
      emitter = &this->m_emitter->m_particle_system.pointer->m_lods.pointer->m_emitters_array.pointer[i];
      if ( emitter->m_event.pointer == evt && emitter->m_visibility )
        found_emitter = 1;
    }
  }
  if ( found_emitter )
  {
    for ( j = 0; !j; j = 1 )
    {
      for ( k = 0; k < this->m_emitter->m_particle_system.pointer->m_lods.pointer->m_num_emitters; ++k )
      {
        v5 = &this->m_emitter->m_particle_system.pointer->m_lods.pointer->m_emitters_array.pointer[k];
        if ( v5->m_event.pointer == evt && v5->m_event.pointer->m_visibility )
        {
          instance = vostok::particle::particle_world::create_emitter_instance(v5, 1, 0);
          vostok::particle::particle_emitter_instance::set_transform(instance, transform);
          vostok::particle::particle_system_instance_impl::add_emitter_instance(
            this->m_particle_system_instance,
            0,
            instance);
        }
      }
    }
  }
}
