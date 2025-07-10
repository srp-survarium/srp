void __thiscall vostok::network::login_client_impl::ping(
        vostok::network::login_client_impl *this,
        unsigned int retry_count)
{
  __int128 v2; // [esp-Ch] [ebp-BCh]
  boost::asio::mutable_buffers_1 buffers; // [esp+9Ch] [ebp-14h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf3<void,vostok::network::login_client_impl,unsigned int,boost::system::error_code const &,unsigned int>,boost::_bi::list4<boost::_bi::value<vostok::network::login_client_impl *>,boost::_bi::value<unsigned int>,boost::arg<1>,boost::arg<2> > > result; // [esp+A4h] [ebp-Ch] BYREF

  HIDWORD(v2) = this;
  if ( this->m_client_state == 3 )
  {
    if ( retry_count )
    {
      buffers.data_ = &this->m_session_id;
      buffers.size_ = 4;
      *(boost::_bi::bind_t<void,boost::_mfi::mf3<void,vostok::network::login_client_impl,unsigned int,boost::system::error_code const &,unsigned int>,boost::_bi::list4<boost::_bi::value<vostok::network::login_client_impl *>,boost::_bi::value<unsigned int>,boost::arg<1>,boost::arg<2> > > *)&v2 = *boost::bind<void,vostok::network::login_client_impl,unsigned int,boost::system::error_code const &,unsigned int,vostok::network::login_client_impl *,unsigned int,boost::arg<1>,boost::arg<2>>(&result, vostok::network::login_client_impl::on_ping_sent, this, retry_count);
      boost::asio::detail::win_iocp_socket_service_base::async_send<boost::asio::mutable_buffers_1,boost::_bi::bind_t<void,boost::_mfi::mf3<void,vostok::network::login_client_impl,unsigned int,boost::system::error_code const &,unsigned int>,boost::_bi::list4<boost::_bi::value<vostok::network::login_client_impl *>,boost::_bi::value<unsigned int>,boost::arg<1>,boost::arg<2>>>>(
        (boost::asio::detail::win_iocp_socket_service_base *)(*(_DWORD *)(HIDWORD(v2) + 240) + 20),
        (boost::asio::detail::win_iocp_socket_service_base::base_implementation_type *)(HIDWORD(v2) + 244),
        &buffers,
        0,
        v2);
    }
    else
    {
      this->m_client_state = signed_in;
    }
  }
}
