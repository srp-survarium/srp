void __thiscall vostok::network::login_client_impl::login_client_impl(
        vostok::network::login_client_impl *this,
        vostok::network::login_client_impl *io_service,
        boost::asio::io_service *io_servicea)
{
  boost::asio::ssl::detail::openssl_init<1> *v3; // ecx
  const ssl_method_st *v4; // eax
  ssl_ctx_st *v5; // eax
  boost::asio::ssl::detail::stream_core *v6; // ecx
  boost::asio::error::detail::ssl_category *ssl_category; // esi
  boost::asio::deadline_timer_service<boost::posix_time::ptime,boost::asio::time_traits<boost::posix_time::ptime> > *v8; // ecx
  boost::asio::io_service *v9; // eax
  int error; // ecx
  const boost::system::error_category *v11; // eax
  int (__cdecl *verify_callback)(int, x509_store_ctx_st *); // eax
  boost::asio::ssl::stream<boost::asio::basic_stream_socket<boost::asio::ip::tcp,boost::asio::stream_socket_service<boost::asio::ip::tcp> > &> *v13; // ecx
  boost::_bi::bind_t<bool,boost::_mfi::mf2<bool,vostok::network::login_client_impl,bool,boost::asio::ssl::verify_context &>,boost::_bi::list3<boost::_bi::value<vostok::network::login_client_impl *>,boost::arg<1>,boost::arg<2> > > v14; // [esp-8h] [ebp-40h]
  boost::asio::ssl::detail::stream_core *v15; // [esp-4h] [ebp-3Ch]
  boost::asio::ssl::detail::stream_core *v16; // [esp-4h] [ebp-3Ch]
  int v17; // [esp+0h] [ebp-38h]
  boost::system::error_code *v18; // [esp+0h] [ebp-38h]
  int v19; // [esp+4h] [ebp-34h]
  int v20; // [esp+8h] [ebp-30h]
  boost::asio::ip::basic_endpoint<boost::asio::ip::udp> endpoint; // [esp+Ch] [ebp-2Ch] BYREF
  boost::system::error_code ec; // [esp+28h] [ebp-10h] BYREF
  boost::system::error_code result; // [esp+30h] [ebp-8h] BYREF

  boost::asio::basic_stream_socket<boost::asio::ip::tcp,boost::asio::stream_socket_service<boost::asio::ip::tcp>>::basic_stream_socket<boost::asio::ip::tcp,boost::asio::stream_socket_service<boost::asio::ip::tcp>>(
    io_servicea,
    &io_service->m_socket);
  io_service->m_ssl_context.handle_ = 0;
  boost::asio::ssl::detail::openssl_init<1>::openssl_init<1>(v3, &io_service->m_ssl_context.init_.ref_);
  v4 = SSLv23_method();
  v5 = SSL_CTX_new(v4);
  v6 = v15;
  io_service->m_ssl_context.handle_ = v5;
  if ( !v5 )
  {
    ssl_category = boost::asio::error::get_ssl_category();
    result.m_val = ERR_get_error();
    result.m_cat = ssl_category;
    if ( (result.m_val != 0 ? (unsigned int)vostok::memory::process_allocator::finalize_impl : 0) != 0 )
    {
      boost::asio::detail::do_throw_error(&result, "context");
      v6 = v16;
    }
  }
  boost::asio::ssl::stream<boost::asio::basic_stream_socket<boost::asio::ip::tcp,boost::asio::stream_socket_service<boost::asio::ip::tcp>> &>::stream<boost::asio::basic_stream_socket<boost::asio::ip::tcp,boost::asio::stream_socket_service<boost::asio::ip::tcp>> &>(
    &io_service->m_ssl_stream,
    &io_service->m_socket,
    v6,
    &io_service->m_ssl_context);
  memset((void *)&endpoint, 0, sizeof(endpoint));
  endpoint.impl_.data_.base.sa_family = 2;
  endpoint.impl_.data_.v4.sin_port = ((int (__stdcall *)(_DWORD, int, int, int, _DWORD))(&off_8E3A98 + 20))(
                                       0,
                                       v17,
                                       v19,
                                       v20,
                                       *(_DWORD *)&endpoint.impl_.data_.base.sa_family);
  endpoint.impl_.data_.v4.sin_addr.S_un.S_addr = 0;
  boost::asio::basic_socket<boost::asio::ip::udp,boost::asio::datagram_socket_service<boost::asio::ip::udp>>::basic_socket<boost::asio::ip::udp,boost::asio::datagram_socket_service<boost::asio::ip::udp>>(
    io_servicea,
    &endpoint,
    &io_service->m_ping_socket);
  ec.m_val = (int)&loc_F4240;
  ec.m_cat = 0;
  boost::asio::basic_io_object<boost::asio::deadline_timer_service<boost::posix_time::ptime,boost::asio::time_traits<boost::posix_time::ptime>>>::basic_io_object<boost::asio::deadline_timer_service<boost::posix_time::ptime,boost::asio::time_traits<boost::posix_time::ptime>>>(
    io_servicea,
    &io_service->m_ping_timer);
  result.m_val = 0;
  result.m_cat = boost::system::system_category();
  boost::asio::deadline_timer_service<boost::posix_time::ptime,boost::asio::time_traits<boost::posix_time::ptime>>::expires_from_now(
    v8,
    (boost::asio::detail::deadline_timer_service<boost::asio::time_traits<boost::posix_time::ptime> >::implementation_type *)io_service->m_ping_timer.service,
    &io_service->m_ping_timer.implementation,
    (boost::posix_time::time_duration *)&ec,
    &result);
  if ( (result.m_val != 0 ? (unsigned int)vostok::memory::process_allocator::finalize_impl : 0) != 0 )
    boost::asio::detail::do_throw_error(&result, "expires_from_now");
  v9 = io_servicea;
  io_service->m_connection_state = unresolved;
  io_service->m_session_id = 0;
  io_service->m_io_service = v9;
  io_service->m_host_port = -1;
  io_service->m_client_state = signed_in;
  io_service->m_in_destructor = 0;
  io_service->m_server_browser_address[0] = 0;
  io_service->m_server_browser_initial_query[0] = 0;
  stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>(
    (stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *)&endpoint.impl_.data_.v6.sin6_flowinfo,
    "../../resources/ssl/survarium_login_server.crt",
    (const stlp_std::allocator<char> *)&io_servicea + 3);
  boost::system::system_category();
  if ( SSL_CTX_load_verify_locations(
         io_service->m_ssl_context.handle_,
         (const char *)endpoint.impl_.data_.v6.sin6_scope_id,
         0) == 1 )
  {
    v11 = boost::system::system_category();
    error = 0;
  }
  else
  {
    io_servicea = (boost::asio::io_service *)boost::asio::error::get_ssl_category();
    error = ERR_get_error();
    v11 = (const boost::system::error_category *)io_servicea;
  }
  result.m_val = error;
  result.m_cat = v11;
  if ( (error != 0 ? (unsigned int)vostok::memory::process_allocator::finalize_impl : 0) != 0 )
    boost::asio::detail::do_throw_error(&result, "load_verify_file");
  stlp_std::priv::_String_base<char,stlp_std::allocator<char>>::_M_deallocate_block((stlp_std::priv::_String_base<char,stlp_std::allocator<char> > *)&endpoint.impl_.data_.v6.sin6_flowinfo);
  boost::system::system_category();
  verify_callback = SSL_get_verify_callback(io_service->m_ssl_stream.core_.engine_.ssl_);
  SSL_set_verify(io_service->m_ssl_stream.core_.engine_.ssl_, 1, verify_callback);
  boost::system::system_category();
  result.m_val = 0;
  v14.l_.a1_.t_ = io_service;
  result.m_cat = boost::system::system_category();
  v14.f_.f_ = (bool (__thiscall *)(vostok::network::login_client_impl *, bool, boost::asio::ssl::verify_context *))vostok::network::login_client_impl::verify_ssl_certificate;
  boost::asio::ssl::stream<boost::asio::basic_stream_socket<boost::asio::ip::tcp,boost::asio::stream_socket_service<boost::asio::ip::tcp>> &>::set_verify_callback<boost::_bi::bind_t<bool,boost::_mfi::mf2<bool,vostok::network::login_client_impl,bool,boost::asio::ssl::verify_context &>,boost::_bi::list3<boost::_bi::value<vostok::network::login_client_impl *>,boost::arg<1>,boost::arg<2>>>>(
    v13,
    (int)&io_service->m_ssl_stream,
    &ec,
    &result,
    v14,
    v18);
  if ( (result.m_val != 0 ? (unsigned int)vostok::memory::process_allocator::finalize_impl : 0) != 0 )
    boost::asio::detail::do_throw_error(&result, "set_verify_callback");
  io_service->m_host[0] = 0;
  io_service->m_host_ip[0] = 0;
}
