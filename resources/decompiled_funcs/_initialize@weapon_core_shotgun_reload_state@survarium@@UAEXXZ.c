void __thiscall survarium::weapon_core_shotgun_reload_state::initialize(
        survarium::weapon_core_shotgun_reload_state *this)
{
  int v1; // eax
  boost::_bi::list4<enum vostok::connection_error_types_enum &,enum vostok::handshaking_error_types_enum &,enum vostok::socket_error_types_enum &,enum vostok::lobby_server_message_types_enum &> *v2; // ecx
  vostok::socket_error_types_enum *v3; // eax

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  v3 = boost::_bi::list3<char const * &,enum survarium::hit_affects_type_enum &,enum survarium::affect_event_type_enum &>::operator[](
         v2,
         v1);
  vostok::ai::fsm::set_initial_state(this->m_logic, (vostok::ai::fsm_state *)v3);
  this->m_animation_has_been_ended = 0;
}
