void __userpurge survarium::network_client::process_player_kd_stats(
        vostok::network_core::packet_reader *packet@<eax>,
        unsigned int a2@<ecx>,
        survarium::network_client *this)
{
  const unsigned __int8 *m_pointer; // ecx
  char v4; // dl
  unsigned int v5; // edx

  m_pointer = packet->m_pointer;
  v4 = *m_pointer++;
  packet->m_pointer = m_pointer;
  LOBYTE(a2) = v4;
  v5 = *(_DWORD *)m_pointer;
  m_pointer += 4;
  packet->m_pointer = m_pointer;
  packet->m_pointer = m_pointer + 4;
  survarium::game_world_ui::set_player_kills_deaths(
    (survarium::game_world_ui *)this,
    (unsigned __int8)&this->m_game->m_fps_graph,
    a2,
    v5);
}
