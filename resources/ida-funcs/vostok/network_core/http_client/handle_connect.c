void __thiscall vostok::network_core::http_client::handle_connect(
        vostok::network_core::http_client *this,
        boost::asio::ip::basic_endpoint<boost::asio::ip::tcp> *err,
        boost::asio::ip::basic_resolver_iterator<boost::asio::ip::tcp> endpoint_iterator)
{
  boost::detail::shared_count *index; // ecx
  boost::detail::shared_count *v6; // ecx
  boost::asio::basic_socket<boost::asio::ip::udp,boost::asio::datagram_socket_service<boost::asio::ip::udp> > *v7; // ecx
  boost::detail::shared_count **v8; // eax
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::network_core::http_client,boost::system::error_code const &,boost::asio::ip::basic_resolver_iterator<boost::asio::ip::tcp> >,boost::_bi::list3<boost::_bi::value<vostok::network_core::http_client *>,boost::arg<1>,boost::_bi::value<boost::asio::ip::basic_resolver_iterator<boost::asio::ip::tcp> > > > *v9; // eax
  boost::asio::basic_socket<boost::asio::ip::tcp,boost::asio::stream_socket_service<boost::asio::ip::tcp> > *v10; // ecx
  boost::detail::shared_count *v11; // ecx
  boost::asio::ip::basic_resolver_iterator<boost::asio::ip::tcp> v12; // [esp-Ch] [ebp-4Ch] BYREF
  boost::asio::ip::basic_endpoint<boost::asio::ip::tcp> handler; // [esp+10h] [ebp-30h] BYREF
  _BYTE v14[8]; // [esp+2Ch] [ebp-14h] BYREF
  boost::asio::ip::basic_resolver_iterator<boost::asio::ip::tcp> b; // [esp+34h] [ebp-Ch] BYREF
  bool peer_endpoint_3; // [esp+4Bh] [ebp+Bh]

  if ( *(_DWORD *)&err->impl_.data_.base.sa_family )
  {
    memset(&b, 0, sizeof(b));
    peer_endpoint_3 = boost::asio::ip::operator!=(&endpoint_iterator, &b);
    boost::detail::shared_count::~shared_count(v6, (volatile signed __int32 **)&b.values_.pn);
    if ( peer_endpoint_3 )
    {
      boost::asio::basic_socket<boost::asio::ip::tcp,boost::asio::stream_socket_service<boost::asio::ip::tcp>>::close(
        v7,
        (int)&this->m_socket);
      qmemcpy(&handler, &endpoint_iterator.values_.px->_M_impl._M_start[endpoint_iterator.index_], sizeof(handler));
      v8 = boost::asio::ip::basic_resolver_iterator<boost::asio::ip::tcp>::operator++(
             0,
             (boost::detail::shared_count **)&endpoint_iterator);
      boost::asio::ip::basic_resolver_iterator<boost::asio::ip::tcp>::basic_resolver_iterator<boost::asio::ip::tcp>(
        &v12,
        (const boost::asio::ip::basic_resolver_iterator<boost::asio::ip::tcp> *)v8);
      v9 = boost::bind<void,vostok::network_core::http_client,boost::system::error_code const &,boost::asio::ip::basic_resolver_iterator<boost::asio::ip::tcp>,vostok::network_core::http_client *,boost::arg<1>,boost::asio::ip::basic_resolver_iterator<boost::asio::ip::tcp>>(
             (int)v14,
             (boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::network_core::http_client,boost::system::error_code const &,boost::asio::ip::basic_resolver_iterator<boost::asio::ip::tcp> >,boost::_bi::list3<boost::_bi::value<vostok::network_core::http_client *>,boost::arg<1>,boost::_bi::value<boost::asio::ip::basic_resolver_iterator<boost::asio::ip::tcp> > > > *)this,
             (void (__thiscall *)(vostok::network_core::http_client *, const boost::system::error_code *, boost::asio::ip::basic_resolver_iterator<boost::asio::ip::tcp>))*(unsigned __int8 *)boost::asio::placeholders::`anonymous namespace'::error,
             (vostok::network_core::http_client *)v12.values_.px,
             (volatile signed __int32 *)v12.values_.pn.pi_);
      boost::asio::basic_socket<boost::asio::ip::tcp,boost::asio::stream_socket_service<boost::asio::ip::tcp>>::async_connect<boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::network_core::http_client,boost::system::error_code const &,boost::asio::ip::basic_resolver_iterator<boost::asio::ip::tcp>>,boost::_bi::list3<boost::_bi::value<vostok::network_core::http_client *>,boost::arg<1>,boost::_bi::value<boost::asio::ip::basic_resolver_iterator<boost::asio::ip::tcp>>>>>(
        v10,
        (const boost::asio::ip::basic_endpoint<boost::asio::ip::tcp> *)&this->m_socket,
        &handler,
        v9);
      boost::detail::shared_count::~shared_count(v11, (volatile signed __int32 **)&b.values_.pn);
    }
    else
    {
      vostok::network_core::http_client::on_error(
        (const boost::system::error_code *)err,
        (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)v7,
        this);
    }
  }
  else
  {
    b.index_ = (unsigned int)this;
    b.values_.pn.pi_ = (boost::detail::sp_counted_base *)vostok::network_core::http_client::handle_write_request;
    boost::asio::async_write<boost::asio::basic_stream_socket<boost::asio::ip::tcp,boost::asio::stream_socket_service<boost::asio::ip::tcp>>,stlp_std::allocator<char>,boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::network_core::http_client,boost::system::error_code const &>,boost::_bi::list2<boost::_bi::value<vostok::network_core::http_client *>,boost::arg<1>>>>(
      &this->m_request_buff,
      (const boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::network_core::http_client,boost::system::error_code const &>,boost::_bi::list2<boost::_bi::value<vostok::network_core::http_client *>,boost::arg<1> > > *)&b.values_.pn,
      &this->m_socket);
    index = (boost::detail::shared_count *)v12.index_;
  }
  boost::detail::shared_count::~shared_count(index, (volatile signed __int32 **)&endpoint_iterator.values_.pn);
}
