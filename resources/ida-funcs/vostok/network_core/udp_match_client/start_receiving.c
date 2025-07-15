void __thiscall vostok::network_core::udp_match_client::start_receiving(vostok::network_core::udp_match_client *this)
{
  vostok::network_core::custom_alloc_handler<boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::network_core::udp_match_client,boost::system::error_code const &,unsigned int>,boost::_bi::list3<boost::_bi::value<vostok::network_core::udp_match_client *>,boost::arg<1>,boost::arg<2> > > > v1; // [esp-Ch] [ebp-DCh]
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::network_core::udp_match_client,boost::system::error_code const &,unsigned int>,boost::_bi::list3<boost::_bi::value<vostok::network_core::udp_match_client *>,boost::arg<1>,boost::arg<2> > > v3; // [esp+A8h] [ebp-28h]
  boost::asio::mutable_buffers_1 buffers; // [esp+B0h] [ebp-20h] BYREF
  vostok::network_core::handler_allocator *p_m_handler_allocator; // [esp+B8h] [ebp-18h]
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::network_core::udp_match_client,boost::system::error_code const &,unsigned int>,boost::_bi::list3<boost::_bi::value<vostok::network_core::udp_match_client *>,boost::arg<1>,boost::arg<2> > > v6; // [esp+BCh] [ebp-14h]
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::sound::sound_debug_stats>,boost::_bi::list1<boost::_bi::value<vostok::sound::sound_debug_stats *> > > result; // [esp+C4h] [ebp-Ch] BYREF
  char v8; // [esp+CFh] [ebp-1h]

  v8 = 0;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  this->m_is_receiving = 1;
  v3 = (boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::network_core::udp_match_client,boost::system::error_code const &,unsigned int>,boost::_bi::list3<boost::_bi::value<vostok::network_core::udp_match_client *>,boost::arg<1>,boost::arg<2> > >)*boost::bind<void,vostok::sound::sound_debug_stats,vostok::sound::sound_debug_stats *>((boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::ai::working_memory,vostok::ai::game_object const &>,boost::_bi::list2<boost::_bi::value<vostok::ai::working_memory *>,boost::arg<1> > > *)&result, (void (__thiscall *)(vostok::sound::sound_debug_stats *))vostok::network_core::udp_match_client::handle_receive, (vostok::sound::sound_debug_stats *)this);
  p_m_handler_allocator = &this->m_handler_allocator;
  v6 = v3;
  buffers.data_ = &this->m_receive_buffer;
  buffers.size_ = 256;
  v1.m_allocator = &this->m_handler_allocator;
  v1.handler_ = v3;
  boost::asio::detail::win_iocp_socket_service<boost::asio::ip::udp>::async_receive_from<boost::asio::mutable_buffers_1,vostok::network_core::custom_alloc_handler<boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::network_core::udp_match_client,boost::system::error_code const &,unsigned int>,boost::_bi::list3<boost::_bi::value<vostok::network_core::udp_match_client *>,boost::arg<1>,boost::arg<2>>>>>(
    &this->m_socket.service->service_impl_,
    &this->m_socket.implementation,
    &buffers,
    &this->m_remote_endpoint,
    0,
    v1);
}
