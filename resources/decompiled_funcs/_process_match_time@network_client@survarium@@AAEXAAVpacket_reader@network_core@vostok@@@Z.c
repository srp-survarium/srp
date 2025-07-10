void __fastcall survarium::network_client::process_match_time(
        int a1,
        vostok::network_core::packet_reader *packet,
        survarium::network_client *this)
{
  const unsigned __int8 *m_pointer; // ecx
  unsigned int v4; // eax

  m_pointer = packet->m_pointer;
  v4 = *(_DWORD *)m_pointer;
  packet->m_pointer = m_pointer + 4;
  survarium::game_world_ui::set_match_time(&this->m_game->m_game_world.game_ui, v4);
}
