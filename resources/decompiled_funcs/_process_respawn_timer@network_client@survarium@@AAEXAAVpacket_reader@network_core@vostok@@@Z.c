void __fastcall survarium::network_client::process_respawn_timer(
        int a1,
        vostok::network_core::packet_reader *packet,
        survarium::network_client *this)
{
  const unsigned __int8 *m_pointer; // eax
  survarium::game_world_ui *v4; // ecx

  m_pointer = packet->m_pointer;
  v4 = *(survarium::game_world_ui **)m_pointer;
  packet->m_pointer = m_pointer + 4;
  survarium::game_world_ui::set_respawn_time(v4, (unsigned int)&this->m_game->m_game_world.game_ui);
}
