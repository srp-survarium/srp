void __thiscall vostok::network_core::tcp_packet_client::tcp_packet_client(
        vostok::network_core::tcp_packet_client *this,
        boost::asio::io_service *io_service)
{
  boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *v2; // ecx
  boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *v3; // ecx
  boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *v4; // ecx
  boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *v5; // ecx
  boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *v6; // ecx
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v7; // ecx
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::network_core::tcp_packet_client,enum vostok::network_core::client_error_codes_enum,boost::system::error_code>,boost::_bi::list3<boost::_bi::value<vostok::network_core::tcp_packet_client *>,boost::arg<1>,boost::arg<2> > > f; // [esp+2Ch] [ebp-3Ch]
  vostok::memory::base_allocator *v10; // [esp+38h] [ebp-30h]
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::sound::sound_debug_stats>,boost::_bi::list1<boost::_bi::value<vostok::sound::sound_debug_stats *> > > result; // [esp+40h] [ebp-28h] BYREF
  boost::function2<void,enum vostok::network_core::client_error_codes_enum,boost::system::error_code> v12; // [esp+48h] [ebp-20h] BYREF

  survarium::weapon_core::cast_weapon_core((survarium::game_options *)this);
  boost::asio::basic_io_object<boost::asio::stream_socket_service<boost::asio::ip::tcp>>::basic_io_object<boost::asio::stream_socket_service<boost::asio::ip::tcp>>(
    &this->m_socket,
    io_service);
  v10 = vostok::network_core::g_allocator;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)vostok::network_core::g_allocator);
  boost::function1<void,vostok::ai::brain_unit const *>::function1<void,vostok::ai::brain_unit const *>((boost::function<bool __cdecl(void)> *)&this->m_packet_socket);
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(v2, &this->m_packet_socket.m_on_error.vtable);
  vostok::network_core::handler_allocator::handler_allocator(&this->m_packet_socket.m_allocator);
  this->m_packet_socket.m_packet_allocator = v10;
  this->m_packet_socket.m_socket = (boost::asio::basic_stream_socket<boost::asio::ip::tcp,boost::asio::stream_socket_service<boost::asio::ip::tcp> > *)this;
  vostok::network_core::async_connector::async_connector(&this->m_async_connector);
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(v3, &this->m_on_connected.vtable);
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(v4, &this->m_on_disconnected.vtable);
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)&this->m_on_packet_received,
    &this->m_on_packet_received.vtable);
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(v5, &this->m_on_error.vtable);
  this->m_io_service = io_service;
  f = (boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::network_core::tcp_packet_client,enum vostok::network_core::client_error_codes_enum,boost::system::error_code>,boost::_bi::list3<boost::_bi::value<vostok::network_core::tcp_packet_client *>,boost::arg<1>,boost::arg<2> > >)*boost::bind<void,vostok::sound::sound_debug_stats,vostok::sound::sound_debug_stats *>((boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::ai::working_memory,vostok::ai::game_object const &>,boost::_bi::list2<boost::_bi::value<vostok::ai::working_memory *>,boost::arg<1> > > *)&result, (void (__thiscall *)(vostok::sound::sound_debug_stats *))vostok::network_core::tcp_packet_client::on_error, (vostok::sound::sound_debug_stats *)this);
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(v6, &v12);
  boost::function2<void,enum vostok::network_core::client_error_codes_enum,boost::system::error_code>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::network_core::tcp_packet_client,enum vostok::network_core::client_error_codes_enum,boost::system::error_code>,boost::_bi::list3<boost::_bi::value<vostok::network_core::tcp_packet_client *>,boost::arg<1>,boost::arg<2>>>>(
    &v12,
    f);
  boost::function<void __cdecl (unsigned char,vostok::network_core::packet_reader &)>::operator=(
    (boost::function<void __cdecl(unsigned int,unsigned int)> *)&v12,
    (boost::function2<void,unsigned int,unsigned int> *)&this->m_packet_socket.m_on_error);
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    v7,
    (int *)&v12);
}
