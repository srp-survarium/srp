void __thiscall survarium::weapon_core::serialize(
        survarium::weapon_core *this,
        vostok::network_core::udp_match_packet *packet,
        unsigned int client_offset)
{
  vostok::ai::fsm *m_logic; // ecx
  int v4; // eax
  boost::_bi::list4<enum vostok::connection_error_types_enum &,enum vostok::handshaking_error_types_enum &,enum vostok::socket_error_types_enum &,enum vostok::lobby_server_message_types_enum &> *v5; // ecx
  survarium::game_camera *v6; // ecx
  vostok::socket_error_types_enum *i; // [esp+28h] [ebp-Ch]
  unsigned __int8 state_id; // [esp+2Eh] [ebp-6h]
  const vostok::ai::fsm_state *current; // [esp+30h] [ebp-4h]

  survarium::inventory_item::serialize(&this->survarium::inventory_item, packet, client_offset);
  vostok::network_core::packet<vostok::network_core::udp_match_packet>::append(packet, *(float *)&this->m_random.m_seed);
  vostok::network_core::packet<vostok::network_core::udp_match_packet>::append(
    packet,
    *(float *)&this->m_normal_random.m_seed);
  vostok::network_core::packet<vostok::network_core::udp_match_packet>::append(packet, this->m_target);
  vostok::network_core::packet<vostok::network_core::udp_match_packet>::append(
    packet,
    *(float *)&this->m_old_actions_mask);
  vostok::network_core::packet<vostok::network_core::udp_match_packet>::append(packet, this->m_ammo_in_magazine);
  vostok::network_core::packet<vostok::network_core::udp_match_packet>::append(packet, this->m_bullets_in_queue);
  vostok::network_core::packet<vostok::network_core::udp_match_packet>::append(packet, this->m_fire_queue_type);
  vostok::network_core::packet<vostok::network_core::udp_match_packet>::append(packet, this->m_ammo_slot);
  if ( this->m_is_there_chamber_a_round_state )
    vostok::network_core::packet<vostok::network_core::udp_match_packet>::append(packet, this->m_is_round_chambered);
  if ( this->m_logic->m_current_state )
  {
    vostok::network_core::packet<vostok::network_core::udp_match_packet>::append(packet, this->m_is_shown);
    survarium::hand_to_weapon_ik_processor::serialize(&this->m_hand_ik_processor, packet, client_offset);
    state_id = 0;
    m_logic = this->m_logic;
    current = m_logic->m_current_state;
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)m_logic);
    i = boost::_bi::list3<char const * &,enum survarium::hit_affects_type_enum &,enum survarium::affect_event_type_enum &>::operator[](
          v5,
          v4);
    while ( i )
    {
      v6 = (survarium::game_camera *)i;
      if ( i == (vostok::socket_error_types_enum *)current )
        break;
      v6 = (survarium::game_camera *)i;
      i = (vostok::socket_error_types_enum *)*((_DWORD *)i + 1);
      ++state_id;
    }
    survarium::weapon_user_dead_state::finalize(v6);
    vostok::network_core::packet<vostok::network_core::udp_match_packet>::append(packet, state_id);
    ((void (__thiscall *)(vostok::ai::fsm_state *, vostok::network_core::udp_match_packet *))this->m_logic->m_current_state->__vftable[1].~vostok::ai::fsm_state)(
      this->m_logic->m_current_state,
      packet);
    survarium::weapon_user_animations_selector::serialize(&this->m_user_animations_selector, packet);
  }
}
