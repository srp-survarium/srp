void __thiscall vostok::particle::particle_emitter_instance::play_child(
        vostok::particle::particle_emitter_instance *this,
        vostok::particle::particle_event *evt,
        vostok::particle::particle_event *transform,
        vostok::math::float4x4 *second_transform)
{
  void (__thiscall *load)(vostok::particle::particle_action *, vostok::memory::base_allocator *, const vostok::configs::binary_config_value *); // eax
  int v6; // esi
  char v7; // dl
  _BYTE *v8; // ecx
  vostok::particle::particle_emitter *v9; // eax
  vostok::particle::particle_event *pointer; // ecx
  vostok::particle::particle_emitter_instance *v11; // eax
  vostok::particle::particle_emitter_instance *v12; // esi
  int v13; // [esp-4h] [ebp-18h]
  unsigned int v14; // [esp+10h] [ebp-4h]
  int v15; // [esp+1Ch] [ebp+8h]

  load = evt[15].m_next.pointer[13].__vftable[4].load;
  v6 = *((_DWORD *)load + 4);
  v7 = 0;
  if ( v6 )
  {
    v8 = (_BYTE *)(*((_DWORD *)load + 2) + 370);
    do
    {
      if ( *(vostok::particle::particle_event **)(v8 - 42) == transform && *v8 )
        v7 = 1;
      v8 += 384;
      --v6;
    }
    while ( v6 );
    if ( v7 )
    {
      v14 = 0;
      v15 = 0;
      do
      {
        v9 = (vostok::particle::particle_emitter *)(v15 + *((_DWORD *)load + 2));
        pointer = v9->m_event.pointer;
        if ( pointer == transform && pointer->m_visibility )
        {
          vostok::particle::particle_world::create_emitter_instance(
            *((vostok::memory::base_allocator **)&evt[11].m_visibility + 1),
            v9,
            1);
          v12 = v11;
          vostok::particle::particle_emitter_instance::set_transform(v13, second_transform, v11, second_transform);
          vostok::particle::particle_system_instance_impl::add_emitter_instance(
            0,
            v12,
            *(vostok::particle::particle_system_instance_impl **)&evt[14].m_visibility);
        }
        ++v14;
        load = evt[15].m_next.pointer[13].__vftable[4].load;
        v15 += 384;
      }
      while ( v14 < *((_DWORD *)load + 4) );
    }
  }
}
