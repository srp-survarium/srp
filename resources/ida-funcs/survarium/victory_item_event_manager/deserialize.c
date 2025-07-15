void __thiscall survarium::victory_item_event_manager::deserialize(
        survarium::victory_item_event_manager *this,
        vostok::network_core::buffer_reader *reader,
        vostok::network_core::buffer_reader *i)
{
  unsigned int *p_m_buffer_size; // edx
  const unsigned __int8 *m_pointer; // esi
  const unsigned __int8 *v6; // eax
  unsigned int j; // ecx
  unsigned int v8; // xmm0_4
  const unsigned __int8 *v9; // esi
  unsigned int v10; // xmm0_4
  const unsigned __int8 *v11; // esi
  unsigned int v12; // xmm0_4
  const unsigned __int8 *v13; // esi
  bool v14; // al
  const unsigned int *v15; // ecx
  int v16; // [esp+18h] [ebp-Ch]
  unsigned int v17; // [esp+1Ch] [ebp-8h]
  const unsigned int *v18; // [esp+20h] [ebp-4h]
  unsigned __int8 v19; // [esp+33h] [ebp+Fh]

  v17 = 0;
  p_m_buffer_size = (unsigned int *)&reader[2].m_buffer_size;
  v18 = &reader[2].m_buffer_size;
  while ( v17 < *((unsigned __int8 *)reader[85].m_buffer + 29783) )
  {
    memset(p_m_buffer_size, 0, 0x50u);
    m_pointer = i->m_pointer;
    v16 = *(_DWORD *)m_pointer;
    v6 = m_pointer + 4;
    i->m_pointer = m_pointer + 4;
    for ( j = 0; j < *((unsigned __int8 *)reader[85].m_buffer + 29772); ++j )
    {
      if ( ((1 << j) & v16) != 0 )
      {
        v8 = *(_DWORD *)v6;
        v6 += 4;
        i->m_pointer = v6;
        p_m_buffer_size[j] = v8;
      }
    }
    v9 = i->m_pointer;
    v10 = *(_DWORD *)v9;
    i->m_pointer = v9 + 4;
    p_m_buffer_size[20] = v10;
    v11 = i->m_pointer;
    v12 = *(_DWORD *)v11;
    i->m_pointer = v11 + 4;
    p_m_buffer_size[21] = v12;
    v13 = i->m_pointer;
    v19 = *v13;
    i->m_pointer = v13 + 1;
    p_m_buffer_size[22] = v19;
    v14 = vostok::network_core::buffer_reader::r<bool>(i);
    v15 = v18;
    ++v17;
    v18 += 24;
    p_m_buffer_size = (unsigned int *)v18;
    *((_BYTE *)v15 + 92) = v14;
  }
}
