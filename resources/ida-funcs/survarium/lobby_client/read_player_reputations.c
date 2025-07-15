char __thiscall survarium::lobby_client::read_player_reputations(
        survarium::lobby_client *this,
        vostok::network_core::buffer_reader *reader,
        int a3)
{
  char *v4; // esi
  _BYTE *v5; // eax
  vostok::memory::doug_lea_allocator *v6; // esi
  char *v7; // eax
  char *v8; // eax
  unsigned __int8 m_buffer_size; // bl
  const char *v11; // [esp+0h] [ebp-10h]
  const char *v12; // [esp+4h] [ebp-Ch]
  unsigned int v13; // [esp+8h] [ebp-8h]
  char v14; // [esp+1Bh] [ebp+Bh]

  if ( reader[1061].m_pointer )
  {
    vostok::memory::doug_lea_allocator::free_impl(
      (vostok::memory::doug_lea_allocator *)this,
      (int)survarium::g_allocator,
      (char *)reader[1061].m_pointer,
      v11,
      v12,
      v13);
    reader[1061].m_pointer = 0;
  }
  v4 = *(char **)(a3 + 4);
  v5 = v4 + 1;
  v14 = *v4;
  v6 = survarium::g_allocator;
  *(_DWORD *)(a3 + 4) = v5;
  LOBYTE(reader[1061].m_buffer_size) = v14;
  v7 = type_info::raw_name(&survarium::player_reputation `RTTI Type Descriptor');
  v8 = vostok::memory::doug_lea_allocator::malloc_impl(
         (vostok::memory::doug_lea_allocator *)(8 * LOBYTE(reader[1061].m_buffer_size)),
         (int)v6,
         8 * LOBYTE(reader[1061].m_buffer_size),
         v7,
         v11,
         v12,
         v13);
  reader[1061].m_pointer = (const unsigned __int8 *)v8;
  m_buffer_size = reader[1061].m_buffer_size;
  if ( m_buffer_size )
  {
    memcpy((unsigned __int8 *)v8, *(unsigned __int8 **)(a3 + 4), 8 * m_buffer_size);
    *(_DWORD *)(a3 + 4) += 8 * m_buffer_size;
  }
  return 1;
}
