char __thiscall survarium::lobby_client::read_player_skills(
        survarium::lobby_client *this,
        vostok::network_core::buffer_reader *reader,
        int a3)
{
  int *v4; // esi
  unsigned __int8 v5; // dl
  vostok::network_core::buffer_reader *v6; // eax
  const unsigned __int8 **v7; // esi
  unsigned int *v8; // esi
  char *v9; // esi
  _BYTE *v10; // eax
  vostok::memory::doug_lea_allocator *v11; // esi
  char *v12; // eax
  unsigned __int8 *v13; // eax
  vostok::memory::doug_lea_allocator *v14; // ecx
  unsigned int v15; // esi
  char *v16; // esi
  _BYTE *v17; // eax
  vostok::memory::doug_lea_allocator *v18; // esi
  char *v19; // eax
  char *v20; // eax
  unsigned __int8 m_buffer_size; // cl
  int v22; // esi
  const char *v24; // [esp+0h] [ebp-10h]
  const char *v25; // [esp+0h] [ebp-10h]
  const char *v26; // [esp+4h] [ebp-Ch]
  const char *v27; // [esp+4h] [ebp-Ch]
  unsigned int v28; // [esp+8h] [ebp-8h]
  unsigned int v29; // [esp+8h] [ebp-8h]
  int v30; // [esp+1Ch] [ebp+Ch]
  const unsigned __int8 *v31; // [esp+1Ch] [ebp+Ch]
  unsigned int v32; // [esp+1Ch] [ebp+Ch]
  const unsigned __int8 *v33; // [esp+1Ch] [ebp+Ch]
  char v34; // [esp+1Fh] [ebp+Fh]
  char v35; // [esp+1Fh] [ebp+Fh]
  char v36; // [esp+1Fh] [ebp+Fh]

  if ( reader[1060].m_buffer_size )
  {
    vostok::memory::doug_lea_allocator::free_impl(
      (vostok::memory::doug_lea_allocator *)this,
      (int)survarium::g_allocator,
      (char *)reader[1060].m_buffer_size,
      v24,
      v26,
      v28);
    reader[1060].m_buffer_size = 0;
  }
  v4 = *(int **)(a3 + 4);
  v30 = *v4;
  v5 = 0;
  *(_DWORD *)(a3 + 4) = v4 + 1;
  if ( LOBYTE(reader[50].m_buffer_size) )
  {
    while ( reader[126 * v5 + 51].m_buffer_size != v30 )
    {
      if ( ++v5 >= LOBYTE(reader[50].m_buffer_size) )
        goto LABEL_8;
    }
    v34 = *((_BYTE *)v4 + 4);
    *(_DWORD *)(a3 + 4) = (char *)v4 + 5;
    v6 = &reader[126 * v5];
    HIBYTE(v6[176].m_buffer_size) = v34;
    v7 = *(const unsigned __int8 ***)(a3 + 4);
    v31 = *v7;
    *(_DWORD *)(a3 + 4) = v7 + 1;
    v6[175].m_pointer = v31;
    v8 = *(unsigned int **)(a3 + 4);
    v32 = *v8;
    *(_DWORD *)(a3 + 4) = v8 + 1;
    v6[175].m_buffer_size = v32;
    v33 = **(const unsigned __int8 ***)(a3 + 4);
    *(_DWORD *)(a3 + 4) += 4;
    v6[176].m_buffer = v33;
  }
LABEL_8:
  v9 = *(char **)(a3 + 4);
  v10 = v9 + 1;
  v35 = *v9;
  v11 = survarium::g_allocator;
  *(_DWORD *)(a3 + 4) = v10;
  LOBYTE(reader[1061].m_buffer) = v35;
  v12 = type_info::raw_name(&survarium::player_skill `RTTI Type Descriptor');
  v13 = (unsigned __int8 *)vostok::memory::doug_lea_allocator::malloc_impl(
                             (vostok::memory::doug_lea_allocator *)(2 * LOBYTE(reader[1061].m_buffer)),
                             (int)v11,
                             2 * LOBYTE(reader[1061].m_buffer),
                             v12,
                             v24,
                             v26,
                             v28);
  LOBYTE(v14) = reader[1061].m_buffer;
  v15 = 2 * (unsigned __int8)v14;
  reader[1060].m_buffer_size = (const unsigned int)v13;
  if ( (_BYTE)v14 )
  {
    memcpy(v13, *(unsigned __int8 **)(a3 + 4), v15);
    *(_DWORD *)(a3 + 4) += v15;
  }
  if ( reader[1095].m_pointer )
  {
    vostok::memory::doug_lea_allocator::free_impl(
      v14,
      (int)survarium::g_allocator,
      (char *)reader[1095].m_pointer,
      v25,
      v27,
      v29);
    reader[1095].m_pointer = 0;
  }
  v16 = *(char **)(a3 + 4);
  v17 = v16 + 1;
  v36 = *v16;
  v18 = survarium::g_allocator;
  *(_DWORD *)(a3 + 4) = v17;
  LOBYTE(reader[1095].m_buffer_size) = v36;
  v19 = type_info::raw_name(&unsigned char `RTTI Type Descriptor');
  v20 = vostok::memory::doug_lea_allocator::malloc_impl(
          (vostok::memory::doug_lea_allocator *)LOBYTE(reader[1095].m_buffer_size),
          (int)v18,
          LOBYTE(reader[1095].m_buffer_size),
          v19,
          v25,
          v27,
          v29);
  m_buffer_size = reader[1095].m_buffer_size;
  reader[1095].m_pointer = (const unsigned __int8 *)v20;
  v22 = m_buffer_size;
  if ( m_buffer_size )
  {
    memcpy((unsigned __int8 *)v20, *(unsigned __int8 **)(a3 + 4), m_buffer_size);
    *(_DWORD *)(a3 + 4) += v22;
  }
  return 1;
}
