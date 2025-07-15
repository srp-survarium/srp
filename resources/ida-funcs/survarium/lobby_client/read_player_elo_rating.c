char __thiscall survarium::lobby_client::read_player_elo_rating(
        survarium::lobby_client *this,
        vostok::network_core::buffer_reader *reader,
        vostok::network_core::buffer_reader *a3)
{
  const unsigned __int8 *m_pointer; // esi
  unsigned __int16 v5; // ax
  survarium::lobby_menu *v6; // ecx
  vostok::network_core::buffer_reader *v8; // [esp+1Ch] [ebp+Ch]

  m_pointer = a3->m_pointer;
  v8 = *(vostok::network_core::buffer_reader **)m_pointer;
  a3->m_pointer = m_pointer + 4;
  LOWORD(m_pointer) = vostok::network_core::buffer_reader::r<unsigned short>(a3);
  v5 = vostok::network_core::buffer_reader::r<unsigned short>(a3);
  survarium::lobby_menu::set_player_elo_rating(
    v6,
    *((_DWORD *)reader[5].m_pointer + 3460),
    (unsigned int)v8,
    (unsigned __int16)m_pointer,
    v5);
  return 1;
}
