char __thiscall survarium::messaging_client::read_ignore_list(
        survarium::messaging_client *this,
        vostok::network_core::buffer_reader *reader,
        vostok::network_core::buffer_reader *a3)
{
  stlp_std::vector<survarium::account_list_item,vostok::vectora_allocator<void *> > *v4; // edi
  const unsigned int *p_m_buffer_size; // esi
  unsigned __int8 *v6; // eax
  const unsigned __int8 *m_pointer; // esi
  vostok::network_core::buffer_reader *v8; // ecx
  const survarium::account_list_item *v10; // [esp+0h] [ebp-60h]
  unsigned __int8 dst[72]; // [esp+10h] [ebp-50h] BYREF
  vostok::network_core::buffer_reader *v12; // [esp+58h] [ebp-8h]
  const unsigned int *v13; // [esp+5Ch] [ebp-4h]
  stlp_std::vector<survarium::account_list_item,vostok::vectora_allocator<void *> > *v14; // [esp+68h] [ebp+8h]
  vostok::network_core::buffer_reader *v15; // [esp+6Ch] [ebp+Ch]

  v4 = (stlp_std::vector<survarium::account_list_item,vostok::vectora_allocator<void *> > *)vostok::network_core::buffer_reader::r<unsigned short>(a3);
  memset((int)dst, 0, sizeof(dst));
  p_m_buffer_size = &reader[30].m_buffer_size;
  v13 = &reader[30].m_buffer_size;
  stlp_std::vector<survarium::account_list_item,vostok::vectora_allocator<void *>>::resize(
    v4,
    (int)&reader[30].m_buffer_size,
    (const stlp_std::__true_type *)dst,
    v10);
  if ( v4 )
  {
    v15 = 0;
    v14 = v4;
    while ( 1 )
    {
      v6 = (unsigned __int8 *)v15 + *p_m_buffer_size;
      m_pointer = a3->m_pointer;
      v12 = *(vostok::network_core::buffer_reader **)m_pointer;
      a3->m_pointer = m_pointer + 4;
      v8 = v12;
      *(_DWORD *)v6 = v12;
      vostok::network_core::buffer_reader::r_string(v8, (char *)a3, v6 + 4);
      v15 += 6;
      v14 = (stlp_std::vector<survarium::account_list_item,vostok::vectora_allocator<void *> > *)((char *)v14 - 1);
      if ( !v14 )
        break;
      p_m_buffer_size = v13;
    }
  }
  return 1;
}
