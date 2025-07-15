void __thiscall vostok::network_core::http_client::handle_resolve(
        vostok::network_core::http_client *this,
        const boost::system::error_code *err,
        boost::asio::ip::basic_resolver_iterator<boost::asio::ip::tcp> endpoint_iterator)
{
  boost::asio::ip::basic_resolver_iterator<boost::asio::ip::tcp> v3; // [esp-Ch] [ebp-10Ch] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::network_core::http_client,boost::system::error_code const &,boost::asio::ip::basic_resolver_iterator<boost::asio::ip::tcp> >,boost::_bi::list3<boost::_bi::value<vostok::network_core::http_client *>,boost::arg<1>,boost::_bi::value<boost::asio::ip::basic_resolver_iterator<boost::asio::ip::tcp> > > > *handler; // [esp+8h] [ebp-F8h]
  vostok::network_core::http_client *thisa; // [esp+Ch] [ebp-F4h]
  boost::detail::shared_count *v6; // [esp+10h] [ebp-F0h]
  boost::detail::shared_count *v7; // [esp+14h] [ebp-ECh]
  boost::asio::ip::basic_resolver_iterator<boost::asio::ip::tcp> *v8; // [esp+74h] [ebp-8Ch]
  boost::detail::shared_count *p_pn; // [esp+78h] [ebp-88h]
  boost::detail::sp_counted_base *pi; // [esp+7Ch] [ebp-84h]
  boost::asio::ip::basic_resolver_entry<boost::asio::ip::tcp> *v11; // [esp+A4h] [ebp-5Ch]
  boost::asio::ip::basic_resolver_entry<boost::asio::ip::tcp> *M_start; // [esp+A8h] [ebp-58h]
  stlp_std::vector<boost::asio::ip::basic_resolver_entry<boost::asio::ip::tcp>,stlp_std::allocator<boost::asio::ip::basic_resolver_entry<boost::asio::ip::tcp> > > *px; // [esp+ACh] [ebp-54h]
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::network_core::http_client,boost::system::error_code const &,boost::asio::ip::basic_resolver_iterator<boost::asio::ip::tcp> >,boost::_bi::list3<boost::_bi::value<vostok::network_core::http_client *>,boost::arg<1>,boost::_bi::value<boost::asio::ip::basic_resolver_iterator<boost::asio::ip::tcp> > > > result; // [esp+B0h] [ebp-50h] BYREF
  _BYTE v15[28]; // [esp+C8h] [ebp-38h] BYREF
  boost::asio::ip::basic_endpoint<boost::asio::ip::tcp> endpoint; // [esp+E4h] [ebp-1Ch] BYREF

  thisa = this;
  if ( err->m_val )
  {
    vostok::network_core::http_client::on_error(thisa, err);
  }
  else
  {
    px = endpoint_iterator.values_.px;
    M_start = endpoint_iterator.values_.px->_M_impl._M_start;
    v11 = &M_start[endpoint_iterator.index_];
    qmemcpy(v15, v11, sizeof(v15));
    qmemcpy(&endpoint, v15, sizeof(endpoint));
    boost::asio::ip::basic_resolver_iterator<boost::asio::ip::tcp>::increment(&endpoint_iterator);
    v8 = &v3;
    v3.values_.px = endpoint_iterator.values_.px;
    p_pn = &v3.values_.pn;
    v3.values_.pn.pi_ = endpoint_iterator.values_.pn.pi_;
    if ( endpoint_iterator.values_.pn.pi_ )
    {
      pi = p_pn->pi_;
      _InterlockedExchangeAdd(&pi->use_count_, 1u);
    }
    v8->index_ = endpoint_iterator.index_;
    handler = boost::bind<void,vostok::network_core::http_client,boost::system::error_code const &,boost::asio::ip::basic_resolver_iterator<boost::asio::ip::tcp>,vostok::network_core::http_client *,boost::arg<1>,boost::asio::ip::basic_resolver_iterator<boost::asio::ip::tcp>>(
                &result,
                vostok::network_core::http_client::handle_connect,
                thisa,
                *(boost::arg<1> *)boost::asio::placeholders::`anonymous namespace'::error,
                v3);
    boost::asio::basic_socket<boost::asio::ip::tcp,boost::asio::stream_socket_service<boost::asio::ip::tcp>>::async_connect<boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::network_core::http_client,boost::system::error_code const &,boost::asio::ip::basic_resolver_iterator<boost::asio::ip::tcp>>,boost::_bi::list3<boost::_bi::value<vostok::network_core::http_client *>,boost::arg<1>,boost::_bi::value<boost::asio::ip::basic_resolver_iterator<boost::asio::ip::tcp>>>>>(
      &thisa->m_socket,
      &endpoint,
      handler);
    v7 = &result.l_.a3_.t_.values_.pn;
    if ( result.l_.a3_.t_.values_.pn.pi_ )
      boost::detail::sp_counted_base::release(v7->pi_);
  }
  v6 = &endpoint_iterator.values_.pn;
  if ( endpoint_iterator.values_.pn.pi_ )
    boost::detail::sp_counted_base::release(v6->pi_);
}
