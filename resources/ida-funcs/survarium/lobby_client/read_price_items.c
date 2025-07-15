unsigned __int8 __fastcall survarium::lobby_client::read_price_items(
        survarium::lobby_client *this,
        int a2,
        vostok::network_core::buffer_reader *reader)
{
  const unsigned __int8 *m_pointer; // esi
  int v5; // edi
  unsigned __int16 v6; // ax
  vostok::memory::doug_lea_allocator *v7; // esi
  char *v8; // eax
  unsigned __int8 *v9; // eax
  unsigned int v10; // esi
  const char *v12; // [esp+0h] [ebp-Ch]
  const char *v13; // [esp+4h] [ebp-8h]
  unsigned int v14; // [esp+8h] [ebp-4h]
  unsigned __int8 v15; // [esp+17h] [ebp+Bh]

  m_pointer = reader->m_pointer;
  v15 = *m_pointer;
  reader->m_pointer = m_pointer + 1;
  v5 = a2 + 8 * v15 + 12744;
  *(_BYTE *)(a2 + 8 * v15 + 12750) = v15;
  v6 = vostok::network_core::buffer_reader::r<unsigned short>(reader);
  *(_WORD *)(v5 + 4) = v6;
  if ( v6 )
  {
    v7 = survarium::g_allocator;
    v8 = type_info::raw_name(&survarium::price_item `RTTI Type Descriptor');
    v9 = (unsigned __int8 *)vostok::memory::doug_lea_allocator::malloc_impl(
                              (vostok::memory::doug_lea_allocator *)(12 * *(unsigned __int16 *)(v5 + 4)),
                              (int)v7,
                              12 * *(unsigned __int16 *)(v5 + 4),
                              v8,
                              v12,
                              v13,
                              v14);
    v10 = 12 * *(unsigned __int16 *)(v5 + 4);
    *(_DWORD *)v5 = v9;
    memcpy(v9, (unsigned __int8 *)reader->m_pointer, v10);
    reader->m_pointer += v10;
  }
  return v15;
}
