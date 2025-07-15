void __thiscall vostok::network_core::udp_match_connection::send(
        vostok::network_core::udp_match_connection *this,
        vostok::network_core::udp_match_packet *packet)
{
  stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > *v2; // ecx
  survarium::base_project::resolve_link_object *v3; // esi
  survarium::base_project::resolve_link_object *v4; // esi
  survarium::base_project::resolve_link_object *v5; // esi
  vostok::network_core::custom_alloc_handler<boost::_bi::bind_t<void,boost::_mfi::mf3<void,vostok::network_core::udp_match_connection,vostok::network_core::udp_match_packet *,boost::system::error_code const &,unsigned int>,boost::_bi::list4<boost::_bi::value<vostok::network_core::udp_match_connection *>,boost::_bi::value<vostok::network_core::udp_match_packet *>,boost::arg<1>,boost::arg<2> > > > v6; // [esp-10h] [ebp-10Ch]
  boost::_bi::bind_t<void,boost::_mfi::mf3<void,vostok::network_core::tcp_packet_socket<boost::asio::basic_stream_socket<boost::asio::ip::tcp,boost::asio::stream_socket_service<boost::asio::ip::tcp> > >,vostok::network_core::tcp_packet const *,boost::system::error_code const &,unsigned int>,boost::_bi::list4<boost::_bi::value<vostok::network_core::tcp_packet_socket<boost::asio::basic_stream_socket<boost::asio::ip::tcp,boost::asio::stream_socket_service<boost::asio::ip::tcp> > > *>,boost::_bi::value<vostok::network_core::tcp_packet *>,boost::arg<1>,boost::arg<2> > > v8; // [esp+C4h] [ebp-38h]
  boost::asio::mutable_buffers_1 buffers; // [esp+D8h] [ebp-24h] BYREF
  vostok::network_core::handler_allocator *p_m_handler_allocator; // [esp+E0h] [ebp-1Ch]
  stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > v11; // [esp+E4h] [ebp-18h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_voice,void *>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_voice *>,boost::_bi::value<void *> > > result; // [esp+F0h] [ebp-Ch] BYREF

  v2 = (stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > *)(this->m_stats.sent.packets.count + 1);
  this->m_stats.sent.packets.count = (unsigned int)v2;
  v3 = stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object>>::end(
         v2,
         (int)packet);
  this->m_stats.sent.messages.bytes += (unsigned int)v3
                                     + (unsigned __int8)vostok::network_core::udp_match_packet::header_size(packet);
  v4 = stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object>>::end(
         (stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > *)this,
         (int)packet);
  this->m_stats.sent.packets.bytes += (unsigned int)&v4[1].config.id.max_storage
                                    + (unsigned __int8)vostok::network_core::udp_match_packet::header_size(packet)
                                    + 6;
  ++this->m_pending_operations_count;
  v8 = *boost::bind<void,vostok::network::match_client,vostok::network_core::udp_network_flow_emulator_options const *,vostok::network::match_client *,vostok::network_core::udp_network_flow_emulator_options const *>(
          (boost::_bi::bind_t<void,boost::_mfi::mf3<void,vostok::network_core::tcp_packet_socket<boost::asio::basic_stream_socket<boost::asio::ip::tcp,boost::asio::stream_socket_service<boost::asio::ip::tcp> > >,vostok::network_core::tcp_packet const *,boost::system::error_code const &,unsigned int>,boost::_bi::list4<boost::_bi::value<vostok::network_core::tcp_packet_socket<boost::asio::basic_stream_socket<boost::asio::ip::tcp,boost::asio::stream_socket_service<boost::asio::ip::tcp> > > *>,boost::_bi::value<vostok::network_core::tcp_packet *>,boost::arg<1>,boost::arg<2> > > *)&result,
          (void (__thiscall *)(vostok::sound::sound_voice *, void *))vostok::network_core::udp_match_connection::handle_send,
          (vostok::sound::sound_voice *)this,
          (vostok::network_core::tcp_packet *)packet);
  p_m_handler_allocator = &this->m_handler_allocator;
  v11 = (stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> >)v8;
  v5 = stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object>>::end(
         &v11,
         (int)packet);
  buffers.data_ = &packet->m_buffer;
  buffers.size_ = (unsigned int)v5 + (unsigned __int8)vostok::network_core::udp_match_packet::header_size(packet);
  *(_QWORD *)&v6.m_allocator = __PAIR64__((unsigned int)v11._M_start, (unsigned int)&this->m_handler_allocator);
  v6.handler_.l_ = *(boost::_bi::list4<boost::_bi::value<vostok::network_core::udp_match_connection *>,boost::_bi::value<vostok::network_core::udp_match_packet *>,boost::arg<1>,boost::arg<2> > *)&v11._M_finish;
  boost::asio::detail::win_iocp_socket_service<boost::asio::ip::udp>::async_send_to<boost::asio::mutable_buffers_1,vostok::network_core::custom_alloc_handler<boost::_bi::bind_t<void,boost::_mfi::mf3<void,vostok::network_core::udp_match_connection,vostok::network_core::udp_match_packet *,boost::system::error_code const &,unsigned int>,boost::_bi::list4<boost::_bi::value<vostok::network_core::udp_match_connection *>,boost::_bi::value<vostok::network_core::udp_match_packet *>,boost::arg<1>,boost::arg<2>>>>>(
    &this->m_socket->service->service_impl_,
    &this->m_socket->implementation,
    &buffers,
    this->m_remote_endpoint,
    0,
    v6);
}
