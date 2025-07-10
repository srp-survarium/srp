char __userpurge survarium::messaging_client::read_friend_list@<al>(
        vostok::network_core::packet_reader *reader@<esi>,
        survarium::messaging_client *this)
{
  const unsigned __int8 *m_pointer; // eax
  unsigned __int16 v3; // cx
  int v4; // ebx
  vostok::vectora<survarium::account_list_item> *p_m_friend_list; // edi
  const unsigned __int8 *v6; // eax
  int v7; // ecx
  unsigned __int8 *v8; // edi
  const unsigned __int8 *v9; // eax
  unsigned int v10; // ebx
  const unsigned __int8 *v11; // eax
  unsigned __int8 v12; // cl
  bool v13; // zf
  int v15; // [esp+8h] [ebp-3Ch]
  vostok::vectora<survarium::account_list_item> *v16; // [esp+Ch] [ebp-38h]
  survarium::account_list_item __x; // [esp+10h] [ebp-34h] BYREF
  survarium::messaging_client *thisa; // [esp+48h] [ebp+4h]

  m_pointer = reader->m_pointer;
  v3 = *(_WORD *)m_pointer;
  reader->m_pointer = m_pointer + 2;
  v4 = v3;
  __x.account_name.m_begin = __x.account_name.m_buffer;
  p_m_friend_list = &this->m_friend_list;
  __x.account_name.m_end = __x.account_name.m_buffer;
  __x.account_name.m_max_end = (char *)&__x.online;
  __x.account_name.m_buffer[0] = 0;
  v16 = &this->m_friend_list;
  stlp_std::priv::_Impl_vector<survarium::account_list_item,vostok::vectora_allocator<survarium::account_list_item>>::resize(
    v3,
    &this->m_friend_list._M_impl,
    &__x);
  if ( v4 )
  {
    thisa = 0;
    v15 = v4;
    while ( 1 )
    {
      v6 = reader->m_pointer;
      v7 = *(_DWORD *)v6;
      v8 = (unsigned __int8 *)thisa + (unsigned int)p_m_friend_list->_M_impl._M_start;
      reader->m_pointer = v6 + 4;
      *(_DWORD *)v8 = v7;
      v9 = reader->m_pointer;
      v10 = *v9;
      reader->m_pointer = v9 + 1;
      memcpy(v8 + 16, (unsigned __int8 *)v9 + 1, v10);
      reader->m_pointer += v10;
      thisa = (survarium::messaging_client *)((char *)thisa + 52);
      v8[v10 + 16] = 0;
      v11 = reader->m_pointer;
      v12 = *v11;
      v13 = v15-- == 1;
      reader->m_pointer = v11 + 1;
      v8[48] = v12;
      if ( v13 )
        break;
      p_m_friend_list = v16;
    }
  }
  return 1;
}
