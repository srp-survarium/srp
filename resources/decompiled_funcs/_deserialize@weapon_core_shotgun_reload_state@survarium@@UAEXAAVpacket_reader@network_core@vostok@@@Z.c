void __thiscall survarium::weapon_core_shotgun_reload_state::deserialize(
        survarium::weapon_core_shotgun_reload_state *this,
        vostok::network_core::packet_reader *reader)
{
  survarium::game_camera *v2; // ecx
  int v3; // eax
  boost::_bi::list4<enum vostok::connection_error_types_enum &,enum vostok::handshaking_error_types_enum &,enum vostok::socket_error_types_enum &,enum vostok::lobby_server_message_types_enum &> *v4; // ecx
  vostok::socket_error_types_enum *v5; // ecx
  vostok::socket_error_types_enum *i; // [esp+Ch] [ebp-Ch]
  unsigned __int8 target_state_id; // [esp+12h] [ebp-6h]
  unsigned __int8 state_id; // [esp+13h] [ebp-5h]
  vostok::ai::fsm_state *current; // [esp+14h] [ebp-4h]

  target_state_id = vostok::network_core::packet_reader::r<unsigned char>(
                      (vostok::network_core::packet_reader *)this,
                      (int)reader);
  state_id = 0;
  current = 0;
  survarium::weapon_user_dead_state::finalize(v2);
  i = boost::_bi::list3<char const * &,enum survarium::hit_affects_type_enum &,enum survarium::affect_event_type_enum &>::operator[](
        v4,
        v3);
  while ( i )
  {
    v5 = (vostok::socket_error_types_enum *)state_id;
    if ( state_id == target_state_id )
    {
      current = (vostok::ai::fsm_state *)i;
      break;
    }
    v5 = i;
    i = (vostok::socket_error_types_enum *)*((_DWORD *)i + 1);
    ++state_id;
  }
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)v5);
  vostok::ai::fsm::set_initial_state(this->m_logic, current);
}
