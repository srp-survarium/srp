char __thiscall survarium::messaging_client::read_friend_list(
        survarium::messaging_client *this,
        vostok::network_core::buffer_reader *reader,
        vostok::network_core::buffer_reader *a3)
{
  stlp_std::vector<survarium::account_list_item,vostok::vectora_allocator<void *> > *v3; // edi
  const unsigned __int8 **p_m_pointer; // esi
  vostok::network_core::buffer_reader *v5; // ecx
  const unsigned __int8 *m_pointer; // eax
  unsigned __int8 *v7; // ebx
  bool v8; // al
  bool v9; // zf
  const survarium::account_list_item *v11; // [esp+0h] [ebp-60h]
  unsigned __int8 dst[72]; // [esp+Ch] [ebp-54h] BYREF
  int v13; // [esp+54h] [ebp-Ch]
  const unsigned __int8 **v14; // [esp+58h] [ebp-8h]
  stlp_std::vector<survarium::account_list_item,vostok::vectora_allocator<void *> > *v15; // [esp+5Ch] [ebp-4h]
  int v16; // [esp+68h] [ebp+8h]

  v3 = (stlp_std::vector<survarium::account_list_item,vostok::vectora_allocator<void *> > *)vostok::network_core::buffer_reader::r<unsigned short>(a3);
  memset((int)dst, 0, sizeof(dst));
  p_m_pointer = &reader[29].m_pointer;
  v14 = &reader[29].m_pointer;
  stlp_std::vector<survarium::account_list_item,vostok::vectora_allocator<void *>>::resize(
    v3,
    (int)&reader[29].m_pointer,
    (const stlp_std::__true_type *)dst,
    v11);
  if ( v3 )
  {
    v16 = 0;
    v15 = v3;
    while ( 1 )
    {
      m_pointer = a3->m_pointer;
      v7 = (unsigned __int8 *)&(*p_m_pointer)[v16];
      v13 = *(_DWORD *)m_pointer;
      a3->m_pointer = m_pointer + 4;
      *(_DWORD *)v7 = v13;
      vostok::network_core::buffer_reader::r_string(v5, (char *)a3, v7 + 4);
      v8 = vostok::network_core::buffer_reader::r<bool>(a3);
      v16 += 72;
      v9 = v15 == (stlp_std::vector<survarium::account_list_item,vostok::vectora_allocator<void *> > *)1;
      v15 = (stlp_std::vector<survarium::account_list_item,vostok::vectora_allocator<void *> > *)((char *)v15 - 1);
      v7[68] = v8;
      if ( v9 )
        break;
      p_m_pointer = v14;
    }
  }
  return 1;
}
