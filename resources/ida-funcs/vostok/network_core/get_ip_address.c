stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *__cdecl vostok::network_core::get_ip_address(
        stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *result,
        boost::asio::io_service *io_service)
{
  boost::asio::ip::basic_resolver_query<boost::asio::ip::tcp> *v2; // ecx
  stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *v3; // eax
  char *M_data; // ebx
  boost::asio::ip::basic_resolver_iterator<boost::asio::ip::tcp> *v5; // ecx
  bool v6; // al
  boost::detail::shared_count *v7; // ecx
  boost::detail::shared_count *v8; // ecx
  boost::shared_ptr<void> *v9; // ecx
  boost::detail::shared_count *v10; // ecx
  boost::asio::ip::basic_resolver_query<boost::asio::ip::tcp> *v12; // [esp-8h] [ebp-E0h]
  boost::asio::ip::resolver_query_base::flags v13; // [esp+0h] [ebp-D8h]
  boost::system::error_code *v14; // [esp+0h] [ebp-D8h]
  boost::asio::ip::basic_resolver_query<boost::asio::ip::tcp> query; // [esp+10h] [ebp-C8h] BYREF
  _BYTE v16[28]; // [esp+60h] [ebp-78h] BYREF
  boost::asio::ip::basic_resolver<boost::asio::ip::tcp,boost::asio::ip::resolver_service<boost::asio::ip::tcp> > v17; // [esp+7Ch] [ebp-5Ch] BYREF
  stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > service; // [esp+88h] [ebp-50h] BYREF
  stlp_std::priv::_String_base<char,stlp_std::allocator<char> > v19; // [esp+A0h] [ebp-38h] BYREF
  boost::asio::ip::address resulta; // [esp+B8h] [ebp-20h] BYREF
  stlp_std::allocator<char> v21; // [esp+D7h] [ebp-1h] BYREF

  boost::asio::ip::basic_resolver<boost::asio::ip::tcp,boost::asio::ip::resolver_service<boost::asio::ip::tcp>>::basic_resolver<boost::asio::ip::tcp,boost::asio::ip::resolver_service<boost::asio::ip::tcp>>(
    io_service,
    &v17);
  stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>(
    &service,
    (char *)uri,
    &v21);
  v12 = v2;
  v3 = boost::asio::ip::host_name((stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *)&v19);
  boost::asio::ip::basic_resolver_query<boost::asio::ip::tcp>::basic_resolver_query<boost::asio::ip::tcp>(
    v12,
    &query,
    v3,
    &service,
    v13);
  stlp_std::priv::_String_base<char,stlp_std::allocator<char>>::_M_deallocate_block(&v19);
  stlp_std::priv::_String_base<char,stlp_std::allocator<char>>::_M_deallocate_block(&service);
  v19._M_finish = 0;
  v19._M_start_of_storage._M_data = (char *)boost::system::system_category();
  boost::asio::detail::resolver_service<boost::asio::ip::tcp>::resolve(
    &query,
    (boost::asio::detail::resolver_service<boost::asio::ip::tcp> *)&service._M_buffers._M_static_buf[12],
    (boost::system::error_code *)&v19._M_finish,
    v14);
  if ( (v19._M_finish != 0 ? (unsigned int)vostok::memory::process_allocator::finalize_impl : 0) != 0 )
    boost::asio::detail::do_throw_error((const boost::system::error_code *)&v19._M_finish, "resolve");
  memset(&v19._M_buffers._M_static_buf[12], 0, 12);
  while ( 1 )
  {
    if ( !boost::asio::ip::operator!=(
            (const boost::asio::ip::basic_resolver_iterator<boost::asio::ip::tcp> *)&service._M_buffers._M_static_buf[12],
            (const boost::asio::ip::basic_resolver_iterator<boost::asio::ip::tcp> *)&v19._M_buffers._M_static_buf[12]) )
    {
      stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>(
        result,
        "unknown",
        &v21);
      goto LABEL_21;
    }
    M_data = service._M_start_of_storage._M_data;
    qmemcpy(
      v16,
      (const void *)(**(_DWORD **)&service._M_buffers._M_static_buf[12] + 76 * (int)service._M_start_of_storage._M_data),
      sizeof(v16));
    boost::asio::ip::detail::endpoint::address(0, (int)v16, &resulta);
    if ( resulta.type_ == ipv4 )
    {
      v6 = (ntohl(resulta.ipv4_address_.addr_.S_un.S_addr) & 0xFF000000) == 2130706432;
      goto LABEL_16;
    }
    if ( resulta.ipv6_address_.addr_.u.Byte[0]
      || __PAIR16__(resulta.ipv6_address_.addr_.u.Byte[1], 0) != resulta.ipv6_address_.addr_.u.Byte[2]
      || __PAIR16__(resulta.ipv6_address_.addr_.u.Byte[3], 0) != resulta.ipv6_address_.addr_.u.Byte[4]
      || __PAIR16__(resulta.ipv6_address_.addr_.u.Byte[5], 0) != resulta.ipv6_address_.addr_.u.Byte[6]
      || __PAIR16__(resulta.ipv6_address_.addr_.u.Byte[7], 0) != resulta.ipv6_address_.addr_.u.Byte[8]
      || __PAIR16__(resulta.ipv6_address_.addr_.u.Byte[9], 0) != resulta.ipv6_address_.addr_.u.Byte[10]
      || __PAIR16__(resulta.ipv6_address_.addr_.u.Byte[11], 0) != resulta.ipv6_address_.addr_.u.Byte[12]
      || __PAIR16__(resulta.ipv6_address_.addr_.u.Byte[13], 0) != resulta.ipv6_address_.addr_.u.Byte[14]
      || resulta.ipv6_address_.addr_.u.Byte[15] != 1 )
    {
      break;
    }
LABEL_18:
    boost::asio::ip::basic_resolver_iterator<boost::asio::ip::tcp>::operator++(
      v5,
      (boost::detail::shared_count **)&service._M_buffers._M_static_buf[12]);
  }
  v6 = 0;
LABEL_16:
  if ( v6 || resulta.type_ )
    goto LABEL_18;
  qmemcpy(v16, (const void *)(**(_DWORD **)&service._M_buffers._M_static_buf[12] + 76 * (_DWORD)M_data), sizeof(v16));
  boost::asio::ip::detail::endpoint::address(0, (int)v16, &resulta);
  boost::asio::ip::address::to_string((boost::asio::ip::address *)result, (int)&resulta);
LABEL_21:
  boost::detail::shared_count::~shared_count(v7, (volatile signed __int32 **)&v19._M_finish);
  boost::detail::shared_count::~shared_count(v8, (volatile signed __int32 **)&service._M_finish);
  stlp_std::priv::_String_base<char,stlp_std::allocator<char>>::_M_deallocate_block(&query.service_name_);
  stlp_std::priv::_String_base<char,stlp_std::allocator<char>>::_M_deallocate_block(&query.host_name_);
  boost::shared_ptr<void>::reset(v9, &v17.implementation.px);
  boost::detail::shared_count::~shared_count(v10, (volatile signed __int32 **)&v17.implementation.pn);
  return result;
}
