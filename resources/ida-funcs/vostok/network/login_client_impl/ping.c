void __thiscall vostok::network::login_client_impl::ping(
        vostok::network::login_client_impl *this,
        vostok::network::login_client_impl *retry_count)
{
  boost::asio::detail::win_iocp_socket_service<boost::asio::ip::udp> *p_service_impl; // [esp-14h] [ebp-30h]
  boost::_bi::bind_t<void,boost::_mfi::mf3<void,vostok::network::login_client_impl,unsigned int,boost::system::error_code const &,unsigned int>,boost::_bi::list4<boost::_bi::value<vostok::network::login_client_impl *>,boost::_bi::value<unsigned int>,boost::arg<1>,boost::arg<2> > > v3; // [esp-8h] [ebp-24h]
  boost::asio::mutable_buffers_1 buffers; // [esp+14h] [ebp-8h] BYREF

  if ( this->m_client_state == 3 )
  {
    if ( retry_count )
    {
      buffers.data_ = &this->m_session_id;
      v3.f_.f_ = (void (__thiscall *)(vostok::network::login_client_impl *, unsigned int, const boost::system::error_code *, unsigned int))this;
      p_service_impl = &this->m_ping_socket.service->service_impl_;
      buffers.size_ = 4;
      v3.l_.a1_.t_ = retry_count;
      boost::asio::detail::win_iocp_socket_service_base::async_send<boost::asio::mutable_buffers_1,boost::_bi::bind_t<void,boost::_mfi::mf3<void,vostok::network::login_client_impl,unsigned int,boost::system::error_code const &,unsigned int>,boost::_bi::list4<boost::_bi::value<vostok::network::login_client_impl *>,boost::_bi::value<unsigned int>,boost::arg<1>,boost::arg<2>>>>(
        &buffers,
        p_service_impl,
        (const boost::shared_ptr<void> *)&this->m_ping_socket.implementation,
        (int)vostok::network::login_client_impl::on_ping_sent,
        v3);
    }
    else
    {
      this->m_client_state = signed_in;
    }
  }
}
