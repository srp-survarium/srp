int __thiscall boost::asio::io_service::run(boost::asio::io_service *this, int a2)
{
  boost::asio::detail::win_iocp_io_service *v2; // edi
  boost::asio::detail::win_iocp_io_service *v3; // ecx
  int v4; // esi
  const boost::system::error_category *v5; // eax
  int m_val; // ecx
  boost::asio::detail::win_iocp_io_service *v7; // ecx
  boost::system::error_code err; // [esp+Ch] [ebp-14h] BYREF
  boost::asio::detail::call_stack<boost::asio::detail::win_iocp_io_service,unsigned char>::context v10; // [esp+14h] [ebp-Ch] BYREF

  err.m_val = 0;
  err.m_cat = boost::system::system_category();
  v2 = *(boost::asio::detail::win_iocp_io_service **)(a2 + 8);
  if ( InterlockedExchangeAdd(&v2->outstanding_work_, 0) )
  {
    boost::asio::detail::call_stack<boost::asio::detail::win_iocp_io_service,unsigned char>::context::context(&v10, v2);
    v4 = 0;
    while ( boost::asio::detail::win_iocp_io_service::do_one(v7, (int)v2, 1, &err) )
    {
      if ( v4 != -1 )
        ++v4;
    }
    TlsSetValue(
      boost::asio::detail::call_stack<boost::asio::detail::win_iocp_io_service,unsigned char>::top_.tss_key_,
      v10.next_);
    m_val = err.m_val;
  }
  else
  {
    boost::asio::detail::win_iocp_io_service::stop(v3, (int)v2);
    v4 = 0;
    v5 = boost::system::system_category();
    m_val = 0;
    err.m_val = 0;
    err.m_cat = v5;
  }
  if ( (m_val != 0 ? (unsigned int)vostok::memory::process_allocator::finalize_impl : 0) != 0 )
    boost::asio::detail::do_throw_error(&err);
  return v4;
}
