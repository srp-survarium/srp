void __thiscall vostok::particle::particle_system::load_lod_actions_binary(
        vostok::particle::particle_system *this,
        vostok::particle::particle_system *lod,
        vostok::mutable_buffer *buffer,
        vostok::mutable_buffer *a4)
{
  vostok::mutable_buffer *v4; // eax
  vostok::particle::particle_emitter *v5; // ebx
  char *v6; // eax
  int v7; // edx
  vostok::particle::particle_action *v8; // eax
  vostok::particle::particle_action *v9; // esi
  char *v10; // [esp+4h] [ebp-Ch]
  int v11; // [esp+8h] [ebp-8h]
  unsigned int v12; // [esp+Ch] [ebp-4h]

  v4 = buffer;
  v10 = 0;
  if ( buffer[2].m_data )
  {
    v11 = 0;
    do
    {
      v5 = (vostok::particle::particle_emitter *)&v4[1].m_data[v11];
      v5->m_actions.pointer = 0;
      v5->m_last_action.pointer = 0;
      v5->m_particle_system.pointer = lod;
      v12 = 0;
      if ( v5->m_num_actions )
      {
        do
        {
          v6 = a4->m_data + 4;
          v7 = *(_DWORD *)a4->m_data;
          a4->m_size -= 4;
          a4->m_data = v6;
          vostok::particle::create_action_by_index(a4, v5, v7);
          v9 = v8;
          if ( v8 )
          {
            v8->load_binary(v8, a4);
            vostok::particle::particle_emitter::add_action(v5, v9);
          }
          ++v12;
        }
        while ( v12 < v5->m_num_actions );
        v4 = buffer;
      }
      ++v10;
      v11 += 384;
    }
    while ( v10 < v4[2].m_data );
  }
}
