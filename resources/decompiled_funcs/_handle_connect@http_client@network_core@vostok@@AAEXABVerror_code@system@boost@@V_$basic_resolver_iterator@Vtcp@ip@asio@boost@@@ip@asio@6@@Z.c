void __thiscall vostok::network_core::http_client::handle_connect(
        vostok::network_core::http_client *this,
        const boost::system::error_code *err,
        boost::asio::ip::basic_resolver_iterator<boost::asio::ip::tcp> endpoint_iterator)
{
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::ai::working_memory,vostok::ai::game_object const &>,boost::_bi::list2<boost::_bi::value<vostok::ai::working_memory *>,boost::arg<1> > > *v3; // eax
  boost::asio::ip::basic_resolver_iterator<boost::asio::ip::tcp> v4; // [esp-Ch] [ebp-190h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::network_core::http_client,boost::system::error_code const &,boost::asio::ip::basic_resolver_iterator<boost::asio::ip::tcp> >,boost::_bi::list3<boost::_bi::value<vostok::network_core::http_client *>,boost::arg<1>,boost::_bi::value<boost::asio::ip::basic_resolver_iterator<boost::asio::ip::tcp> > > > *handler; // [esp+8h] [ebp-17Ch]
  vostok::network_core::http_client *thisa; // [esp+Ch] [ebp-178h]
  boost::detail::shared_count *v7; // [esp+10h] [ebp-174h]
  boost::detail::shared_count *v8; // [esp+14h] [ebp-170h]
  boost::asio::ip::basic_resolver_iterator<boost::asio::ip::tcp> *v9; // [esp+64h] [ebp-120h]
  boost::detail::shared_count *v10; // [esp+68h] [ebp-11Ch]
  boost::detail::sp_counted_base *pi; // [esp+6Ch] [ebp-118h]
  boost::asio::ip::basic_resolver_entry<boost::asio::ip::tcp> *v12; // [esp+94h] [ebp-F0h]
  boost::asio::ip::basic_resolver_entry<boost::asio::ip::tcp> *M_start; // [esp+98h] [ebp-ECh]
  stlp_std::vector<boost::asio::ip::basic_resolver_entry<boost::asio::ip::tcp>,stlp_std::allocator<boost::asio::ip::basic_resolver_entry<boost::asio::ip::tcp> > > *px; // [esp+9Ch] [ebp-E8h]
  boost::detail::shared_count *v15; // [esp+B4h] [ebp-D0h]
  boost::detail::shared_count *p_pn; // [esp+C0h] [ebp-C4h]
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::network_core::http_client,boost::system::error_code const &,boost::asio::ip::basic_resolver_iterator<boost::asio::ip::tcp> >,boost::_bi::list3<boost::_bi::value<vostok::network_core::http_client *>,boost::arg<1>,boost::_bi::value<boost::asio::ip::basic_resolver_iterator<boost::asio::ip::tcp> > > > v17; // [esp+11Ch] [ebp-68h] BYREF
  _BYTE v18[28]; // [esp+134h] [ebp-50h] BYREF
  boost::asio::ip::basic_resolver_iterator<boost::asio::ip::tcp> b; // [esp+150h] [ebp-34h] BYREF
  bool v20; // [esp+15Fh] [ebp-25h]
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::sound::sound_debug_stats>,boost::_bi::list1<boost::_bi::value<vostok::sound::sound_debug_stats *> > > result; // [esp+160h] [ebp-24h] BYREF
  boost::asio::ip::basic_endpoint<boost::asio::ip::tcp> endpoint; // [esp+168h] [ebp-1Ch] BYREF

  thisa = this;
  if ( err->m_val )
  {
    memset(&b, 0, sizeof(b));
    p_pn = &b.values_.pn;
    v20 = boost::asio::ip::operator!=(&endpoint_iterator, &b);
    v15 = &b.values_.pn;
    if ( b.values_.pn.pi_ )
      boost::detail::sp_counted_base::release(v15->pi_);
    if ( v20 )
    {
      boost::asio::basic_socket<boost::asio::ip::tcp,boost::asio::stream_socket_service<boost::asio::ip::tcp>>::close((boost::asio::basic_socket<boost::asio::ip::udp,boost::asio::datagram_socket_service<boost::asio::ip::udp> > *)&thisa->m_socket);
      px = endpoint_iterator.values_.px;
      M_start = endpoint_iterator.values_.px->_M_impl._M_start;
      v12 = &M_start[endpoint_iterator.index_];
      qmemcpy(v18, v12, sizeof(v18));
      qmemcpy(&endpoint, v18, sizeof(endpoint));
      boost::asio::ip::basic_resolver_iterator<boost::asio::ip::tcp>::increment(&endpoint_iterator);
      v9 = &v4;
      v4.values_.px = endpoint_iterator.values_.px;
      v10 = &v4.values_.pn;
      v4.values_.pn.pi_ = endpoint_iterator.values_.pn.pi_;
      if ( endpoint_iterator.values_.pn.pi_ )
      {
        pi = v10->pi_;
        _InterlockedExchangeAdd(&pi->use_count_, 1u);
      }
      v9->index_ = endpoint_iterator.index_;
      handler = boost::bind<void,vostok::network_core::http_client,boost::system::error_code const &,boost::asio::ip::basic_resolver_iterator<boost::asio::ip::tcp>,vostok::network_core::http_client *,boost::arg<1>,boost::asio::ip::basic_resolver_iterator<boost::asio::ip::tcp>>(
                  &v17,
                  vostok::network_core::http_client::handle_connect,
                  thisa,
                  *(boost::arg<1> *)boost::asio::placeholders::`anonymous namespace'::error,
                  v4);
      boost::asio::basic_socket<boost::asio::ip::tcp,boost::asio::stream_socket_service<boost::asio::ip::tcp>>::async_connect<boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::network_core::http_client,boost::system::error_code const &,boost::asio::ip::basic_resolver_iterator<boost::asio::ip::tcp>>,boost::_bi::list3<boost::_bi::value<vostok::network_core::http_client *>,boost::arg<1>,boost::_bi::value<boost::asio::ip::basic_resolver_iterator<boost::asio::ip::tcp>>>>>(
        &thisa->m_socket,
        &endpoint,
        handler);
      v8 = &v17.l_.a3_.t_.values_.pn;
      if ( v17.l_.a3_.t_.values_.pn.pi_ )
        boost::detail::sp_counted_base::release(v8->pi_);
    }
    else
    {
      vostok::network_core::http_client::on_error(thisa, err);
    }
  }
  else
  {
    v3 = boost::bind<void,vostok::sound::sound_debug_stats,vostok::sound::sound_debug_stats *>(
           (boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::ai::working_memory,vostok::ai::game_object const &>,boost::_bi::list2<boost::_bi::value<vostok::ai::working_memory *>,boost::arg<1> > > *)&result,
           (void (__thiscall *)(vostok::sound::sound_debug_stats *))vostok::network_core::http_client::handle_write_request,
           (vostok::sound::sound_debug_stats *)thisa);
    boost::asio::async_write<boost::asio::basic_stream_socket<boost::asio::ip::tcp,boost::asio::stream_socket_service<boost::asio::ip::tcp>>,stlp_std::allocator<char>,boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::network_core::http_client,boost::system::error_code const &>,boost::_bi::list2<boost::_bi::value<vostok::network_core::http_client *>,boost::arg<1>>>>(
      &thisa->m_socket,
      &thisa->m_request_buff,
      (const boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::network_core::http_client,boost::system::error_code const &>,boost::_bi::list2<boost::_bi::value<vostok::network_core::http_client *>,boost::arg<1> > > *)v3);
  }
  v7 = &endpoint_iterator.values_.pn;
  if ( endpoint_iterator.values_.pn.pi_ )
    boost::detail::sp_counted_base::release(v7->pi_);
}
