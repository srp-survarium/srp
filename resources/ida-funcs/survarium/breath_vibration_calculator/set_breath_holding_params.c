void __thiscall survarium::breath_vibration_calculator::set_breath_holding_params(
        survarium::breath_vibration_calculator *this,
        const survarium::breath_holding_params *params)
{
  int v2; // eax
  boost::_bi::list4<enum vostok::connection_error_types_enum &,enum vostok::handshaking_error_types_enum &,enum vostok::socket_error_types_enum &,enum vostok::lobby_server_message_types_enum &> *v3; // ecx
  int v4; // eax
  boost::_bi::list4<enum vostok::connection_error_types_enum &,enum vostok::handshaking_error_types_enum &,enum vostok::socket_error_types_enum &,enum vostok::lobby_server_message_types_enum &> *v5; // ecx
  vostok::socket_error_types_enum *v6; // eax
  vostok::socket_error_types_enum *it; // [esp+18h] [ebp-4h]

  this->m_params = params;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)params);
  for ( it = boost::_bi::list3<char const * &,enum survarium::hit_affects_type_enum &,enum survarium::affect_event_type_enum &>::operator[](
               v3,
               v2); it; it = (vostok::socket_error_types_enum *)*((_DWORD *)it + 1) )
    (*(void (__thiscall **)(vostok::socket_error_types_enum *, const survarium::breath_holding_params *))(*it + 20))(
      it,
      params);
  if ( this->m_params )
  {
    this->m_breath_holding_reserve = this->m_params->max_breath_holding_time;
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
    v6 = boost::_bi::list3<char const * &,enum survarium::hit_affects_type_enum &,enum survarium::affect_event_type_enum &>::operator[](
           v5,
           v4);
    vostok::ai::fsm::set_initial_state(&this->m_logic, (vostok::ai::fsm_state *)v6);
    this->m_target_multiplier = *(float *)&this->m_logic.m_current_state[1].transitions.gap4;
    this->m_current_multiplier = this->m_target_multiplier;
  }
}
