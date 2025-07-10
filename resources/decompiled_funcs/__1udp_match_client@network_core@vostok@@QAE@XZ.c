void __thiscall vostok::network_core::udp_match_client::~udp_match_client(vostok::network_core::udp_match_client *this)
{
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v1; // ecx
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v2; // ecx

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  boost::asio::basic_io_object<boost::asio::datagram_socket_service<boost::asio::ip::udp>>::~basic_io_object<boost::asio::datagram_socket_service<boost::asio::ip::udp>>(&this->m_socket);
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    v1,
    (int *)&this->m_on_disconnect);
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    v2,
    (int *)&this->m_on_packet_received);
  vostok::network_core::udp_match_connection::~udp_match_connection(&this->m_connection);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
}
