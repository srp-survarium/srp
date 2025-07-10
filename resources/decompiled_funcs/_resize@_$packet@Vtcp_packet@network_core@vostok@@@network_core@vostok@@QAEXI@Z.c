void __thiscall vostok::network_core::packet<vostok::network_core::tcp_packet>::resize(
        vostok::network_core::packet<vostok::network_core::tcp_packet> *this,
        unsigned int size)
{
  boost::_bi::list4<enum vostok::connection_error_types_enum &,enum vostok::handshaking_error_types_enum &,enum vostok::socket_error_types_enum &,enum vostok::lobby_server_message_types_enum &> *v2; // ecx

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  if ( (unsigned int)boost::_bi::list4<enum vostok::connection_error_types_enum &,enum vostok::handshaking_error_types_enum &,enum vostok::socket_error_types_enum &,enum vostok::login_server_message_types_enum &>::operator[](
                       v2,
                       (int)this) < size )
    vostok::network_core::packet<vostok::network_core::tcp_packet>::reallocate(this, size);
  this->m_buffer_size = size;
}
