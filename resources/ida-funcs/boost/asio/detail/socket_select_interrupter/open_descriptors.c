void __thiscall boost::asio::detail::socket_select_interrupter::open_descriptors(
        boost::asio::detail::socket_select_interrupter *this,
        unsigned int *a2)
{
  const boost::system::error_category *v2; // eax
  int m_val; // ecx
  int v4; // eax
  const boost::system::error_category *v5; // eax
  unsigned int v6; // esi
  const boost::system::error_category *v7; // eax
  int v8; // ecx
  boost::asio::detail::socket_holder *v9; // ecx
  boost::asio::detail::socket_holder *v10; // ecx
  boost::asio::detail::socket_holder *v11; // ecx
  SOCKET v12; // edi
  const boost::system::error_category *v13; // esi
  int Error; // eax
  const boost::system::error_category *v15; // eax
  sockaddr v16; // [esp+10h] [ebp-34h] BYREF
  boost::system::error_code v17; // [esp+20h] [ebp-24h] BYREF
  unsigned int v18; // [esp+28h] [ebp-1Ch] BYREF
  int v19; // [esp+2Ch] [ebp-18h] BYREF
  int v20; // [esp+30h] [ebp-14h] BYREF
  unsigned int v21; // [esp+34h] [ebp-10h] BYREF
  SOCKET s; // [esp+38h] [ebp-Ch] BYREF
  unsigned __int8 v23[5]; // [esp+3Fh] [ebp-5h] BYREF

  v17.m_val = 0;
  v17.m_cat = boost::system::system_category();
  s = boost::asio::detail::socket_ops::socket(&v17, 2, 1, 6);
  if ( s == -1 && (v17.m_val != 0 ? (unsigned int)vostok::memory::process_allocator::finalize_impl : 0) != 0 )
    boost::asio::detail::do_throw_error(&v17, "socket_select_interrupter");
  v20 = 1;
  v23[0] = 0;
  boost::asio::detail::socket_ops::setsockopt(v23, &v17, s, 0xFFFF, 4, &v20, 4u);
  v16.sa_family = 2;
  *(_DWORD *)&v16.sa_data[6] = 0;
  *(_DWORD *)&v16.sa_data[10] = 0;
  v18 = 16;
  *(_DWORD *)&v16.sa_data[2] = inet_addr("127.0.0.1");
  *(_WORD *)v16.sa_data = 0;
  if ( boost::asio::detail::socket_ops::bind(&v17, 1, s, &v16, 0x10u) == -1
    && (v17.m_val != 0 ? (unsigned int)vostok::memory::process_allocator::finalize_impl : 0) != 0 )
  {
    boost::asio::detail::do_throw_error(&v17, "socket_select_interrupter");
  }
  if ( boost::asio::detail::socket_ops::getsockname(&v18, &v17, s, &v16) == -1
    && (v17.m_val != 0 ? (unsigned int)vostok::memory::process_allocator::finalize_impl : 0) != 0 )
  {
    boost::asio::detail::do_throw_error(&v17, "socket_select_interrupter");
  }
  *(_DWORD *)&v16.sa_data[2] = inet_addr("127.0.0.1");
  if ( s == -1 )
  {
    v2 = boost::system::system_category();
    m_val = 10009;
    v17.m_val = 10009;
    v17.m_cat = v2;
  }
  else
  {
    WSASetLastError(0);
    v4 = listen(s, 0x7FFFFFFF);
    v21 = boost::asio::detail::socket_ops::error_wrapper<int>(&v17, v4);
    if ( v21 )
    {
      m_val = v17.m_val;
    }
    else
    {
      v5 = boost::system::system_category();
      m_val = 0;
      v17.m_val = 0;
      v17.m_cat = v5;
    }
    if ( v21 != -1 )
      goto LABEL_18;
  }
  if ( (m_val != 0 ? (unsigned int)vostok::memory::process_allocator::finalize_impl : 0) != 0 )
    boost::asio::detail::do_throw_error(&v17, "socket_select_interrupter");
LABEL_18:
  v6 = -1;
  v21 = boost::asio::detail::socket_ops::socket(&v17, 2, 1, 6);
  if ( v21 == -1 && (v17.m_val != 0 ? (unsigned int)vostok::memory::process_allocator::finalize_impl : 0) != 0 )
    boost::asio::detail::do_throw_error(&v17, "socket_select_interrupter");
  if ( boost::asio::detail::socket_ops::connect(&v17, 1, v21, &v16, v18) == -1
    && (v17.m_val != 0 ? (unsigned int)vostok::memory::process_allocator::finalize_impl : 0) != 0 )
  {
    boost::asio::detail::do_throw_error(&v17, "socket_select_interrupter");
  }
  if ( s == -1 )
  {
    v7 = boost::system::system_category();
    v8 = 10009;
    v17.m_val = 10009;
    v17.m_cat = v7;
  }
  else
  {
    WSASetLastError(0);
    v18 = 0;
    v12 = accept(s, 0, 0);
    v13 = boost::system::system_category();
    Error = WSAGetLastError();
    v17.m_cat = v13;
    v6 = -1;
    v8 = Error;
    v17.m_val = Error;
    if ( v12 != -1 )
    {
      v15 = boost::system::system_category();
      v17.m_val = 0;
      v6 = v12;
      v17.m_cat = v15;
      goto LABEL_28;
    }
  }
  if ( (v8 != 0 ? (unsigned int)vostok::memory::process_allocator::finalize_impl : 0) != 0 )
    boost::asio::detail::do_throw_error(&v17, "socket_select_interrupter");
LABEL_28:
  v19 = 1;
  v23[0] = 0;
  if ( boost::asio::detail::socket_ops::ioctl(&v17, v21, v23, &v19)
    && (v17.m_val != 0 ? (unsigned int)vostok::memory::process_allocator::finalize_impl : 0) != 0 )
  {
    boost::asio::detail::do_throw_error(&v17, "socket_select_interrupter");
  }
  v20 = 1;
  boost::asio::detail::socket_ops::setsockopt(v23, &v17, v21, 6, 1, &v20, 4u);
  v19 = 1;
  v23[0] = 0;
  if ( boost::asio::detail::socket_ops::ioctl(&v17, v6, v23, &v19)
    && (v17.m_val != 0 ? (unsigned int)vostok::memory::process_allocator::finalize_impl : 0) != 0 )
  {
    boost::asio::detail::do_throw_error(&v17, "socket_select_interrupter");
  }
  v20 = 1;
  boost::asio::detail::socket_ops::setsockopt(v23, &v17, v6, 6, 1, &v20, 4u);
  v9 = (boost::asio::detail::socket_holder *)v21;
  v18 = -1;
  v21 = -1;
  *a2 = v6;
  a2[1] = (unsigned int)v9;
  boost::asio::detail::socket_holder::~socket_holder(v9, &v18);
  boost::asio::detail::socket_holder::~socket_holder(v10, &v21);
  boost::asio::detail::socket_holder::~socket_holder(v11, &s);
}
