void __thiscall survarium::weapon_core_shotgun_reload_state::serialize(
        survarium::weapon_core_shotgun_reload_state *this,
        vostok::network_core::udp_match_packet *packet)
{
  vostok::ai::fsm *m_logic; // ecx
  int v3; // eax
  boost::_bi::list4<enum vostok::connection_error_types_enum &,enum vostok::handshaking_error_types_enum &,enum vostok::socket_error_types_enum &,enum vostok::lobby_server_message_types_enum &> *v4; // ecx
  survarium::game_camera *v5; // ecx
  vostok::socket_error_types_enum *i; // [esp+10h] [ebp-Ch]
  unsigned __int8 state_id; // [esp+16h] [ebp-6h]
  const vostok::ai::fsm_state *current; // [esp+18h] [ebp-4h]

  state_id = 0;
  m_logic = this->m_logic;
  current = m_logic->m_current_state;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)m_logic);
  i = boost::_bi::list3<char const * &,enum survarium::hit_affects_type_enum &,enum survarium::affect_event_type_enum &>::operator[](
        v4,
        v3);
  while ( i )
  {
    v5 = (survarium::game_camera *)i;
    if ( i == (vostok::socket_error_types_enum *)current )
      break;
    v5 = (survarium::game_camera *)i;
    i = (vostok::socket_error_types_enum *)*((_DWORD *)i + 1);
    ++state_id;
  }
  survarium::weapon_user_dead_state::finalize(v5);
  vostok::network_core::packet<vostok::network_core::udp_match_packet>::append(packet, state_id);
}
