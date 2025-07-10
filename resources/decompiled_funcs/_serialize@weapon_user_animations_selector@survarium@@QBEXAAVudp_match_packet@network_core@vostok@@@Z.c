void __thiscall survarium::weapon_user_animations_selector::serialize(
        survarium::weapon_user_animations_selector *this,
        vostok::network_core::udp_match_packet *packet)
{
  survarium::game_camera *v2; // ecx
  vostok::socket_error_types_enum *i; // [esp+14h] [ebp-Ch]
  unsigned __int8 state_id; // [esp+1Ah] [ebp-6h]
  vostok::ai::fsm_state *current; // [esp+1Ch] [ebp-4h]

  state_id = 0;
  current = this->m_logic.m_current_state;
  i = boost::_bi::list3<char const * &,enum survarium::hit_affects_type_enum &,enum survarium::affect_event_type_enum &>::operator[](
        (boost::_bi::list4<enum vostok::connection_error_types_enum &,enum vostok::handshaking_error_types_enum &,enum vostok::socket_error_types_enum &,enum vostok::lobby_server_message_types_enum &> *)current,
        (int)this);
  while ( i && i != (vostok::socket_error_types_enum *)current )
  {
    i = (vostok::socket_error_types_enum *)*((_DWORD *)i + 1);
    LOBYTE(v2) = ++state_id;
  }
  survarium::weapon_user_dead_state::finalize(v2);
  vostok::network_core::packet<vostok::network_core::udp_match_packet>::append(packet, state_id);
  ((void (__thiscall *)(vostok::ai::fsm_state *, vostok::network_core::udp_match_packet *))current->__vftable[1].finalize)(
    current,
    packet);
}
