char __thiscall survarium::messaging_client::read_friend_status(
        survarium::messaging_client *this,
        vostok::network_core::buffer_reader *reader,
        vostok::network_core::buffer_reader *a3)
{
  survarium::messaging_client *v4; // ecx
  const unsigned __int8 *m_pointer; // esi
  bool v6; // al
  survarium::account_list_item *m_buffer_size; // esi
  survarium::account_list_item *v8; // eax
  survarium::messaging_client *v10; // [esp-4h] [ebp-24h]
  survarium::messaging_client *v11; // [esp+10h] [ebp-10h]
  unsigned int v12; // [esp+14h] [ebp-Ch] BYREF
  unsigned int v13; // [esp+18h] [ebp-8h]
  unsigned int v14; // [esp+1Ch] [ebp-4h]
  bool v15; // [esp+2Bh] [ebp+Bh]

  v4 = (survarium::messaging_client *)vostok::network_core::buffer_reader::r<unsigned short>(a3);
  v11 = v4;
  if ( (survarium::messaging_client *)((signed int)(reader[29].m_buffer_size - (unsigned int)reader[29].m_pointer) / 72) != v4 )
  {
LABEL_6:
    survarium::messaging_client::query_for_friend_list(v4, (int)reader);
    return 1;
  }
  v14 = 0;
  if ( v4 )
  {
    while ( 1 )
    {
      m_pointer = a3->m_pointer;
      v13 = *(_DWORD *)m_pointer;
      a3->m_pointer = m_pointer + 4;
      v12 = v13;
      v6 = vostok::network_core::buffer_reader::r<bool>(a3);
      m_buffer_size = (survarium::account_list_item *)reader[29].m_buffer_size;
      v15 = v6;
      v8 = stlp_std::find<survarium::account_list_item *,unsigned int>(
             (survarium::account_list_item *)reader[29].m_pointer,
             &v12,
             m_buffer_size);
      v4 = v10;
      if ( v8 == m_buffer_size )
        break;
      ++v14;
      v8->online = v15;
      if ( v14 >= (unsigned int)v11 )
        return 1;
    }
    goto LABEL_6;
  }
  return 1;
}
