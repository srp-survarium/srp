void __thiscall survarium::hand_to_weapon_ik_processor::deserialize(
        survarium::hand_to_weapon_ik_processor *this,
        vostok::network_core::packet_reader *reader)
{
  vostok::network_core::packet_reader *v2; // ecx
  survarium::game_camera *v3; // ecx
  unsigned __int8 active_hands; // [esp+1Bh] [ebp-1h]

  active_hands = vostok::network_core::packet_reader::r<unsigned char>(
                   (vostok::network_core::packet_reader *)this,
                   (int)reader);
  this->m_hands[0].start_transition_time_in_ms = vostok::network_core::packet_reader::r<unsigned int>(v2, (int)reader);
  this->m_hands[1].start_transition_time_in_ms = vostok::network_core::packet_reader::r<unsigned int>(
                                                   (vostok::network_core::packet_reader *)this,
                                                   (int)reader);
  survarium::weapon_user_dead_state::finalize(v3);
  this->m_hands[0].is_active = (active_hands & 1) != 0;
  this->m_hands[1].is_active = (active_hands & 2) != 0;
}
