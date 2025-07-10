void __thiscall vostok::network_core::tcp_packet_client::~tcp_packet_client(
        vostok::network_core::tcp_packet_client *this)
{
  BOOL v1; // ecx

  v1 = this->m_async_connector.m_connection_state == connection_has_been_established;
  if ( v1 )
    vostok::network_core::tcp_packet_client::disconnect(this);
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    (boost::function<void __cdecl(unsigned int,float,float,char const *)> *)v1,
    (int *)&this->m_on_error);
  boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&this->m_on_packet_received);
  boost::function<void __cdecl (void)>::~function<void __cdecl (void)>((boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag> *)&this->m_on_disconnected);
  boost::function<void __cdecl (void)>::~function<void __cdecl (void)>((boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag> *)&this->m_on_connected);
  vostok::network_core::async_connector::~async_connector(&this->m_async_connector);
  vostok::network_core::tcp_packet_socket<boost::asio::basic_stream_socket<boost::asio::ip::tcp,boost::asio::stream_socket_service<boost::asio::ip::tcp>>>::~tcp_packet_socket<boost::asio::basic_stream_socket<boost::asio::ip::tcp,boost::asio::stream_socket_service<boost::asio::ip::tcp>>>(&this->m_packet_socket);
  boost::asio::basic_io_object<boost::asio::datagram_socket_service<boost::asio::ip::udp>>::~basic_io_object<boost::asio::datagram_socket_service<boost::asio::ip::udp>>((boost::asio::basic_io_object<boost::asio::datagram_socket_service<boost::asio::ip::udp> > *)this);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
}
