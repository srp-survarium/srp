void __thiscall vostok::network_core::udp_match_client::start_receiving(vostok::network_core::udp_match_client *this)
{
  boost::asio::detail::win_iocp_socket_service<boost::asio::ip::udp> *p_service_impl; // [esp-18h] [ebp-38h]
  vostok::network_core::custom_alloc_handler<boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::network_core::udp_match_client,boost::system::error_code const &,unsigned int>,boost::_bi::list3<boost::_bi::value<vostok::network_core::udp_match_client *>,boost::arg<1>,boost::arg<2> > >,vostok::network_core::handler_allocator<1024,96,1> > v2; // [esp-8h] [ebp-28h]
  boost::asio::mutable_buffers_1 buffers; // [esp+Ch] [ebp-14h] BYREF
  vostok::network_core::handler_allocator<1024,96,1> *p_m_handler_allocator; // [esp+14h] [ebp-Ch]
  __int64 v5; // [esp+18h] [ebp-8h]

  LODWORD(v5) = vostok::network_core::udp_match_client::handle_receive;
  buffers.data_ = &this->m_receive_buffer;
  p_m_handler_allocator = &this->m_handler_allocator;
  HIDWORD(v5) = this;
  this->m_is_receiving = 1;
  *(_QWORD *)&v2.m_allocator = v5;
  p_service_impl = &this->m_socket.service->service_impl_;
  buffers.size_ = 1214;
  boost::asio::detail::win_iocp_socket_service<boost::asio::ip::udp>::async_receive_from<boost::asio::mutable_buffers_1,vostok::network_core::custom_alloc_handler<boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::network_core::udp_match_client,boost::system::error_code const &,unsigned int>,boost::_bi::list3<boost::_bi::value<vostok::network_core::udp_match_client *>,boost::arg<1>,boost::arg<2>>>,vostok::network_core::handler_allocator<1024,96,1>>>(
    &buffers,
    p_service_impl,
    &this->m_socket.implementation,
    &this->m_remote_endpoint,
    &this->m_handler_allocator,
    v2);
}
