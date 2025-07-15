void __userpurge vostok::network_core::http_client::get(
        char *server@<eax>,
        const boost::shared_ptr<void> *this,
        char *path,
        boost::function<void __cdecl(void)> *callback)
{
  vostok::network_core::http_client *v4; // ebx
  stlp_std::basic_ostream<char,stlp_std::char_traits<char> > *v6; // ecx
  stlp_std::basic_ostream<char,stlp_std::char_traits<char> > *v7; // ecx
  stlp_std::basic_ostream<char,stlp_std::char_traits<char> > *v8; // ecx
  stlp_std::basic_ostream<char,stlp_std::char_traits<char> > *v9; // ecx
  stlp_std::basic_ostream<char,stlp_std::char_traits<char> > *v10; // ecx
  stlp_std::basic_ostream<char,stlp_std::char_traits<char> > *v11; // ecx
  stlp_std::basic_ostream<char,stlp_std::char_traits<char> > *v12; // ecx
  stlp_std::basic_ostream<char,stlp_std::char_traits<char> > *v13; // ecx
  int v14; // eax
  int v15; // edi
  boost::asio::ip::basic_resolver_query<boost::asio::ip::tcp> *v16; // ecx
  boost::asio::ip::resolver_service<boost::asio::ip::tcp> *service; // esi
  char *p_service_impl; // esi
  boost::function<void __cdecl(void)> *v19; // eax
  boost::detail::sp_counted_base *v20; // ecx
  boost::asio::detail::win_iocp_operation *v21; // eax
  boost::asio::detail::resolve_op<boost::asio::ip::tcp,boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::network_core::http_client,boost::system::error_code const &,boost::asio::ip::basic_resolver_iterator<boost::asio::ip::tcp> >,boost::_bi::list3<boost::_bi::value<vostok::network_core::http_client *>,boost::arg<1>,boost::arg<2> > > >::ptr *v22; // ecx
  boost::weak_ptr<void> v23; // [esp-10h] [ebp-514h] BYREF
  const boost::asio::ip::basic_resolver_query<boost::asio::ip::tcp> *p_query; // [esp-8h] [ebp-50Ch]
  boost::detail::sp_counted_base *v25; // [esp-4h] [ebp-508h]
  boost::asio::ip::resolver_query_base::flags v26; // [esp+0h] [ebp-504h]
  char _Dst[512]; // [esp+10h] [ebp-4F4h] BYREF
  char v28[512]; // [esp+210h] [ebp-2F4h] BYREF
  boost::asio::ip::basic_resolver_query<boost::asio::ip::tcp> query; // [esp+410h] [ebp-F4h] BYREF
  stlp_std::basic_ostream<char,stlp_std::char_traits<char> > v30; // [esp+460h] [ebp-A4h] BYREF
  stlp_std::priv::_String_base<char,stlp_std::allocator<char> > v31; // [esp+4C8h] [ebp-3Ch] BYREF
  stlp_std::priv::_String_base<char,stlp_std::allocator<char> > v32; // [esp+4E0h] [ebp-24h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::network_core::http_client,boost::system::error_code const &,boost::asio::ip::basic_resolver_iterator<boost::asio::ip::tcp> >,boost::_bi::list3<boost::_bi::value<vostok::network_core::http_client *>,boost::arg<1>,boost::arg<2> > > handler; // [esp+4F8h] [ebp-Ch] BYREF

  v4 = (vostok::network_core::http_client *)this;
  stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>::operator=(
    (stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *)&this[22],
    (char *)uri);
  boost::function<void __cdecl (void)>::operator=(
    callback,
    (boost::function1<void,vostok::physics::contact_point const &> *)&v4->m_on_content_downloaded);
  stlp_std::basic_ostream<char,stlp_std::char_traits<char>>::basic_ostream<char,stlp_std::char_traits<char>>(
    &v30,
    &v4->m_request_buff,
    1);
  stlp_std::basic_ostream<char,stlp_std::char_traits<char>>::_M_put_nowiden(v6, (int)&v30, "GET ");
  stlp_std::basic_ostream<char,stlp_std::char_traits<char>>::_M_put_nowiden(v7, (int)&v30, path);
  stlp_std::basic_ostream<char,stlp_std::char_traits<char>>::_M_put_nowiden(v8, (int)&v30, " HTTP/1.0\r\n");
  stlp_std::basic_ostream<char,stlp_std::char_traits<char>>::_M_put_nowiden(v9, (int)&v30, "Host: ");
  stlp_std::basic_ostream<char,stlp_std::char_traits<char>>::_M_put_nowiden(v10, (int)&v30, server);
  stlp_std::basic_ostream<char,stlp_std::char_traits<char>>::_M_put_nowiden(v11, (int)&v30, "\r\n");
  stlp_std::basic_ostream<char,stlp_std::char_traits<char>>::_M_put_nowiden(v12, (int)&v30, "Accept: */*\r\n");
  stlp_std::basic_ostream<char,stlp_std::char_traits<char>>::_M_put_nowiden(v13, (int)&v30, "Connection: close\r\n\r\n");
  strchr(server, 0x3Au);
  v15 = v14;
  if ( v14 )
  {
    strncpy_s(_Dst, 0x200u, server, v14 - (_DWORD)server);
    vostok::strings::copy<512>((char (*)[512])v28, (char *)(v15 + 1));
  }
  else
  {
    vostok::strings::copy<512>((char (*)[512])_Dst, server);
    strcpy_s(v28, 0x200u, "80");
  }
  stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>(
    (stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *)&v31,
    v28,
    (const stlp_std::allocator<char> *)&this + 3);
  stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>(
    (stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *)&v32,
    _Dst,
    (const stlp_std::allocator<char> *)&this + 3);
  boost::asio::ip::basic_resolver_query<boost::asio::ip::tcp>::basic_resolver_query<boost::asio::ip::tcp>(
    v16,
    &query,
    (const stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *)&v32,
    (const stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *)&v31,
    v26);
  stlp_std::priv::_String_base<char,stlp_std::allocator<char>>::_M_deallocate_block(&v32);
  stlp_std::priv::_String_base<char,stlp_std::allocator<char>>::_M_deallocate_block(&v31);
  service = v4->m_resolver.service;
  handler.f_.f_ = vostok::network_core::http_client::handle_resolve;
  p_service_impl = (char *)&service->service_impl_;
  handler.l_.a1_.t_ = v4;
  path = p_service_impl;
  *(_DWORD *)&v32._M_buffers._M_static_buf[12] = &handler;
  v19 = (boost::function<void __cdecl(void)> *)boost::asio::asio_handler_allocate(0x90u, &handler);
  v20 = v25;
  callback = v19;
  if ( v19 )
  {
    v25 = *(boost::detail::sp_counted_base **)p_service_impl;
    LOBYTE(this) = 0;
    p_query = &query;
    v23.pn.pi_ = v20;
    boost::weak_ptr<void>::weak_ptr<void>(
      (boost::weak_ptr<void> *)&v4->m_resolver.implementation,
      &v23.px,
      this,
      (boost::detail::sp_empty)v20);
    boost::asio::detail::resolve_op<boost::asio::ip::tcp,boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::network_core::http_client,boost::system::error_code const &,boost::asio::ip::basic_resolver_iterator<boost::asio::ip::tcp>>,boost::_bi::list3<boost::_bi::value<vostok::network_core::http_client *>,boost::arg<1>,boost::arg<2>>>>::resolve_op<boost::asio::ip::tcp,boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::network_core::http_client,boost::system::error_code const &,boost::asio::ip::basic_resolver_iterator<boost::asio::ip::tcp>>,boost::_bi::list3<boost::_bi::value<vostok::network_core::http_client *>,boost::arg<1>,boost::arg<2>>>>(
      (boost::asio::detail::resolve_op<boost::asio::ip::tcp,boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::network_core::http_client,boost::system::error_code const &,boost::asio::ip::basic_resolver_iterator<boost::asio::ip::tcp> >,boost::_bi::list3<boost::_bi::value<vostok::network_core::http_client *>,boost::arg<1>,boost::arg<2> > > > *)callback,
      &handler,
      v23,
      p_query,
      (boost::asio::detail::win_iocp_io_service *)v25);
    p_service_impl = path;
  }
  else
  {
    v21 = 0;
  }
  boost::asio::detail::resolver_service_base::start_resolve_op(
    (boost::asio::detail::resolver_service_base *)v20,
    (int)p_service_impl,
    v21);
  v32._M_start_of_storage._M_data = 0;
  v32._M_finish = 0;
  boost::asio::detail::resolve_op<boost::asio::ip::tcp,boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::network_core::http_client,boost::system::error_code const &,boost::asio::ip::basic_resolver_iterator<boost::asio::ip::tcp>>,boost::_bi::list3<boost::_bi::value<vostok::network_core::http_client *>,boost::arg<1>,boost::arg<2>>>>::ptr::reset(v22);
  stlp_std::priv::_String_base<char,stlp_std::allocator<char>>::_M_deallocate_block(&query.service_name_);
  stlp_std::priv::_String_base<char,stlp_std::allocator<char>>::_M_deallocate_block(&query.host_name_);
  stlp_std::basic_ostream<char,stlp_std::char_traits<char>>::`vbase destructor'(&v30);
}
