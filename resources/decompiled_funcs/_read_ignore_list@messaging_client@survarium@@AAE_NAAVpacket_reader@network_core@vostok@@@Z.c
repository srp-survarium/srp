char __userpurge survarium::messaging_client::read_ignore_list@<al>(
        vostok::network_core::packet_reader *reader@<esi>,
        survarium::messaging_client *this)
{
  const unsigned __int8 *m_pointer; // eax
  unsigned __int16 v3; // cx
  survarium::messaging_client *v4; // ebx
  vostok::vectora<survarium::account_list_item> *p_m_ignore_list; // edi
  int v6; // ebp
  const unsigned __int8 *v7; // ecx
  unsigned int v8; // edx
  survarium::account_list_item *v9; // eax
  unsigned __int8 *m_buffer; // ebx
  const unsigned __int8 *v11; // eax
  unsigned int v12; // edi
  bool v13; // zf
  vostok::vectora<survarium::account_list_item> *v15; // [esp+8h] [ebp-38h]
  survarium::account_list_item __x; // [esp+Ch] [ebp-34h] BYREF
  survarium::messaging_client *thisa; // [esp+44h] [ebp+4h]

  m_pointer = reader->m_pointer;
  v3 = *(_WORD *)m_pointer;
  reader->m_pointer = m_pointer + 2;
  v4 = (survarium::messaging_client *)v3;
  __x.account_name.m_begin = __x.account_name.m_buffer;
  p_m_ignore_list = &this->m_ignore_list;
  __x.account_name.m_end = __x.account_name.m_buffer;
  __x.account_name.m_max_end = (char *)&__x.online;
  __x.account_name.m_buffer[0] = 0;
  v15 = &this->m_ignore_list;
  stlp_std::priv::_Impl_vector<survarium::account_list_item,vostok::vectora_allocator<survarium::account_list_item>>::resize(
    v3,
    &this->m_ignore_list._M_impl,
    &__x);
  if ( v4 )
  {
    v6 = 0;
    thisa = v4;
    while ( 1 )
    {
      v7 = reader->m_pointer;
      v8 = *(_DWORD *)v7;
      v9 = &p_m_ignore_list->_M_impl._M_start[v6];
      reader->m_pointer = v7 + 4;
      v9->account_id = v8;
      m_buffer = (unsigned __int8 *)v9->account_name.m_buffer;
      v11 = reader->m_pointer;
      v12 = *v11;
      reader->m_pointer = v11 + 1;
      memcpy(m_buffer, (unsigned __int8 *)v11 + 1, v12);
      reader->m_pointer += v12;
      ++v6;
      v13 = thisa == (survarium::messaging_client *)1;
      thisa = (survarium::messaging_client *)((char *)thisa - 1);
      m_buffer[v12] = 0;
      if ( v13 )
        break;
      p_m_ignore_list = v15;
    }
  }
  return 1;
}
