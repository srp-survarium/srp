void __thiscall survarium::jump_logic::set_user(survarium::jump_logic *this, survarium::base_player *user)
{
  int v2; // eax
  boost::_bi::list4<enum vostok::connection_error_types_enum &,enum vostok::handshaking_error_types_enum &,enum vostok::socket_error_types_enum &,enum vostok::lobby_server_message_types_enum &> *v3; // ecx
  vostok::socket_error_types_enum *i; // [esp+8h] [ebp-4h]

  this->m_user = user;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)user);
  for ( i = boost::_bi::list3<char const * &,enum survarium::hit_affects_type_enum &,enum survarium::affect_event_type_enum &>::operator[](
              v3,
              v2); i; i = (vostok::socket_error_types_enum *)*((_DWORD *)i + 1) )
    (*(void (__thiscall **)(vostok::socket_error_types_enum *, survarium::base_player *))(*i + 20))(i, user);
}
