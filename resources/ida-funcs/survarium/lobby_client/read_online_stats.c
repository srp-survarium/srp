char __userpurge survarium::lobby_client::read_online_stats@<al>(
        vostok::network_core::buffer_reader *reader@<eax>,
        survarium::lobby_client *this)
{
  const unsigned __int8 *m_pointer; // esi
  survarium::game *v4; // ecx
  unsigned int v6; // [esp-4h] [ebp-18h]
  unsigned int v7; // [esp+Ch] [ebp-8h]
  unsigned int v8; // [esp+1Ch] [ebp+8h]

  m_pointer = reader->m_pointer;
  v7 = *(_DWORD *)m_pointer;
  reader->m_pointer = m_pointer + 4;
  m_pointer += 4;
  v6 = *(_DWORD *)m_pointer;
  reader->m_pointer = m_pointer + 4;
  v8 = *((_DWORD *)m_pointer + 1);
  reader->m_pointer = m_pointer + 8;
  survarium::lobby_menu::set_online_stats(
    v8,
    (survarium::flash_value *)(m_pointer + 8),
    this->m_game->m_lobby_menu,
    v7,
    v6);
  if ( !v8 )
    survarium::game::exit_and_launch_launcher(v4, this->m_game);
  return 1;
}
