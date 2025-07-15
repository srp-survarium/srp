void __thiscall vostok::network_core::http_client::handle_resolve(
        vostok::network_core::http_client *this,
        const boost::system::error_code *err,
        boost::asio::ip::basic_resolver_iterator<boost::asio::ip::tcp> endpoint_iterator)
{
  boost::detail::shared_count **v4; // eax
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::network_core::http_client,boost::system::error_code const &,boost::asio::ip::basic_resolver_iterator<boost::asio::ip::tcp> >,boost::_bi::list3<boost::_bi::value<vostok::network_core::http_client *>,boost::arg<1>,boost::_bi::value<boost::asio::ip::basic_resolver_iterator<boost::asio::ip::tcp> > > > *v5; // eax
  boost::asio::basic_socket<boost::asio::ip::tcp,boost::asio::stream_socket_service<boost::asio::ip::tcp> > *v6; // ecx
  boost::detail::shared_count *v7; // ecx
  boost::detail::shared_count *v8; // ecx
  boost::asio::ip::basic_resolver_iterator<boost::asio::ip::tcp> v9; // [esp-Ch] [ebp-4Ch] BYREF
  _BYTE v10[12]; // [esp+10h] [ebp-30h] BYREF
  volatile signed __int32 *v11; // [esp+1Ch] [ebp-24h] BYREF
  boost::asio::ip::basic_endpoint<boost::asio::ip::tcp> handler; // [esp+24h] [ebp-1Ch] BYREF

  if ( err->m_val )
  {
    vostok::network_core::http_client::on_error(
      err,
      (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)this,
      this);
  }
  else
  {
    qmemcpy(&handler, &endpoint_iterator.values_.px->_M_impl._M_start[endpoint_iterator.index_], sizeof(handler));
    v4 = boost::asio::ip::basic_resolver_iterator<boost::asio::ip::tcp>::operator++(
           0,
           (boost::detail::shared_count **)&endpoint_iterator);
    boost::asio::ip::basic_resolver_iterator<boost::asio::ip::tcp>::basic_resolver_iterator<boost::asio::ip::tcp>(
      &v9,
      (const boost::asio::ip::basic_resolver_iterator<boost::asio::ip::tcp> *)v4);
    v5 = boost::bind<void,vostok::network_core::http_client,boost::system::error_code const &,boost::asio::ip::basic_resolver_iterator<boost::asio::ip::tcp>,vostok::network_core::http_client *,boost::arg<1>,boost::asio::ip::basic_resolver_iterator<boost::asio::ip::tcp>>(
           (int)v10,
           (boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::network_core::http_client,boost::system::error_code const &,boost::asio::ip::basic_resolver_iterator<boost::asio::ip::tcp> >,boost::_bi::list3<boost::_bi::value<vostok::network_core::http_client *>,boost::arg<1>,boost::_bi::value<boost::asio::ip::basic_resolver_iterator<boost::asio::ip::tcp> > > > *)this,
           (void (__thiscall *)(vostok::network_core::http_client *, const boost::system::error_code *, boost::asio::ip::basic_resolver_iterator<boost::asio::ip::tcp>))*(unsigned __int8 *)boost::asio::placeholders::`anonymous namespace'::error,
           (vostok::network_core::http_client *)v9.values_.px,
           (volatile signed __int32 *)v9.values_.pn.pi_);
    boost::asio::basic_socket<boost::asio::ip::tcp,boost::asio::stream_socket_service<boost::asio::ip::tcp>>::async_connect<boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::network_core::http_client,boost::system::error_code const &,boost::asio::ip::basic_resolver_iterator<boost::asio::ip::tcp>>,boost::_bi::list3<boost::_bi::value<vostok::network_core::http_client *>,boost::arg<1>,boost::_bi::value<boost::asio::ip::basic_resolver_iterator<boost::asio::ip::tcp>>>>>(
      v6,
      (const boost::asio::ip::basic_endpoint<boost::asio::ip::tcp> *)&this->m_socket,
      &handler,
      v5);
    boost::detail::shared_count::~shared_count(v7, &v11);
  }
  boost::detail::shared_count::~shared_count(v8, (volatile signed __int32 **)&endpoint_iterator.values_.pn);
}
