void __thiscall survarium::network_client::process_profiles_action(
        survarium::network_client *this,
        vostok::network_core::buffer_reader *packet)
{
  const unsigned __int8 *m_pointer; // eax
  const unsigned __int8 *v4; // eax
  unsigned int *v5; // esi
  const unsigned __int8 *v6; // eax
  const vostok::network_core::tcp_packet *v7; // eax
  unsigned int v8; // [esp+10h] [ebp-4h]
  unsigned __int8 v9; // [esp+1Ch] [ebp+8h]
  unsigned __int8 v10; // [esp+1Fh] [ebp+Bh]

  m_pointer = packet->m_pointer;
  v10 = *m_pointer;
  v4 = m_pointer + 1;
  packet->m_pointer = v4;
  if ( v10 )
  {
    if ( v10 == 3 )
    {
      v5 = (unsigned int *)v4;
      v6 = v4 + 4;
      v8 = *v5;
      packet->m_pointer = v6;
      v9 = *v6;
      packet->m_pointer = v6 + 1;
      survarium::lobby_menu::set_autobuy_checkbox(
        (survarium::lobby_menu *)this,
        (int)this->m_game->m_lobby_menu,
        v8,
        v9);
    }
  }
  else
  {
    v7 = (const vostok::network_core::tcp_packet *)this->lobby_client(this);
    survarium::lobby_client::read_new_profile(packet, v7);
  }
}
