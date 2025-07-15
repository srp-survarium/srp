void __thiscall survarium::inventory::deserialize(
        survarium::inventory *this,
        vostok::network_core::buffer_reader *reader,
        vostok::network_core::buffer_reader *client_reader,
        unsigned int time_offset,
        int a5)
{
  const unsigned __int8 *m_pointer; // eax
  unsigned int v7; // ecx
  const unsigned __int8 *v8; // esi
  unsigned __int8 v9; // cl
  vostok::network_core::buffer_reader *v10; // eax
  const unsigned __int8 *v11; // esi
  bool v12; // zf
  const unsigned __int8 *v13; // ecx
  const vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *v14; // edi
  int v15; // eax
  vostok::particle::particle_system_instance_impl *m_object; // esi
  const unsigned __int8 *v17; // esi
  const unsigned int *p_m_buffer_size; // esi
  int v19; // edi
  _BYTE *v20; // ecx
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v21; // [esp+Ch] [ebp-14h] BYREF
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v22; // [esp+10h] [ebp-10h] BYREF
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v23; // [esp+14h] [ebp-Ch] BYREF
  int v24; // [esp+18h] [ebp-8h]
  unsigned __int8 v25; // [esp+1Fh] [ebp-1h]
  unsigned __int8 v26; // [esp+2Bh] [ebp+Bh]
  unsigned int v27; // [esp+2Ch] [ebp+Ch]
  unsigned __int8 v28; // [esp+2Fh] [ebp+Fh]
  unsigned __int8 v29; // [esp+2Fh] [ebp+Fh]
  unsigned __int8 v30; // [esp+2Fh] [ebp+Fh]

  v24 = 0;
  m_pointer = client_reader->m_pointer;
  v27 = *(_DWORD *)m_pointer;
  client_reader->m_pointer = m_pointer + 4;
  reader[32].m_buffer_size = v27;
  LOBYTE(reader[33].m_buffer) = vostok::network_core::buffer_reader::r<bool>(client_reader);
  v28 = *client_reader->m_pointer++;
  if ( v28 == 0xFF )
    v7 = 0;
  else
    v7 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)((*(int (__thiscall **)(const unsigned __int8 *))(*(_DWORD *)reader[31].m_pointer
                                                                                            + 12))(reader[31].m_pointer)
                                           + 316)
                               + 50124)
                   + 4 * v28);
  reader[31].m_buffer_size = v7;
  if ( v7 )
    (*(void (__thiscall **)(unsigned int, vostok::network_core::buffer_reader *, unsigned int, int))(*(_DWORD *)v7 + 76))(
      v7,
      client_reader,
      time_offset,
      a5);
  v8 = client_reader->m_pointer;
  v9 = *v8;
  client_reader->m_pointer = v8 + 1;
  v10 = reader;
  LOBYTE(reader[30].m_buffer_size) = v9;
  if ( v9 )
  {
    v11 = client_reader->m_pointer;
    v29 = *v11;
    client_reader->m_pointer = v11 + 1;
    v12 = LOBYTE(reader[30].m_buffer_size) == 0;
    reader[30].m_pointer = (const unsigned __int8 *)(&reader[22].m_buffer_size + v29);
    v30 = 0;
    if ( !v12 )
    {
      do
      {
        v13 = client_reader->m_pointer;
        v25 = *v13;
        v12 = v25 == 0xFF;
        client_reader->m_pointer = v13 + 1;
        if ( v12 )
        {
          v24 |= 1u;
          v21.m_object = 0;
          v14 = (const vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&v21;
        }
        else
        {
          v15 = *((_DWORD *)v10[22].m_buffer + 12400);
          v24 |= 6u;
          vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
            &v22,
            (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(v15 + 4 * v25));
          m_object = v22.m_object;
          v23.m_object = 0;
          if ( v22.m_object )
          {
            vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v23);
            v23.m_object = m_object;
            _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
          }
          v10 = reader;
          v14 = (const vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&v23;
        }
        vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base>::operator=(
          v14,
          (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&v10[30].m_pointer[4 * v30]);
        if ( (v24 & 4) != 0 )
        {
          v24 &= ~4u;
          vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v23);
        }
        if ( (v24 & 2) != 0 )
        {
          v24 &= ~2u;
          vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v22);
        }
        if ( (v24 & 1) != 0 )
        {
          v24 &= ~1u;
          vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v21);
        }
        ++v30;
        v10 = reader;
      }
      while ( v30 < LOBYTE(reader[30].m_buffer_size) );
    }
  }
  v17 = client_reader->m_pointer;
  v26 = *v17;
  client_reader->m_pointer = v17 + 1;
  v10[31].m_buffer = (const unsigned __int8 *)v26;
  p_m_buffer_size = &v10[22].m_buffer_size;
  v19 = 23;
  do
  {
    v20 = (_BYTE *)*p_m_buffer_size;
    if ( *p_m_buffer_size
      && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
    {
      if ( v20[284] )
        (*(void (__thiscall **)(_BYTE *, vostok::network_core::buffer_reader *, unsigned int, int))(*(_DWORD *)v20 + 88))(
          v20,
          client_reader,
          time_offset,
          a5);
    }
    ++p_m_buffer_size;
    --v19;
  }
  while ( v19 );
}
