unsigned int __thiscall boost::asio::io_service::run_one(boost::asio::io_service *this, int a2)
{
  unsigned int v2; // esi
  boost::asio::detail::win_iocp_io_service *v3; // edi
  boost::asio::detail::win_iocp_io_service *v4; // ecx
  const boost::system::error_category *v5; // eax
  int m_val; // ecx
  boost::asio::detail::win_iocp_io_service *v7; // ecx
  boost::asio::detail::call_stack<boost::asio::detail::win_iocp_io_service,unsigned char>::context v9; // [esp+Ch] [ebp-18h] BYREF
  boost::system::error_code v10; // [esp+18h] [ebp-Ch] BYREF

  v2 = 0;
  v10.m_val = 0;
  v10.m_cat = boost::system::system_category();
  v3 = *(boost::asio::detail::win_iocp_io_service **)(a2 + 8);
  if ( InterlockedExchangeAdd(&v3->outstanding_work_, 0) )
  {
    boost::asio::detail::call_stack<boost::asio::detail::win_iocp_io_service,unsigned char>::context::context(&v9, v3);
    v2 = boost::asio::detail::win_iocp_io_service::do_one(v7, (int)v3, 1, &v10);
    TlsSetValue(
      boost::asio::detail::call_stack<boost::asio::detail::win_iocp_io_service,unsigned char>::top_.tss_key_,
      v9.next_);
    m_val = v10.m_val;
  }
  else
  {
    boost::asio::detail::win_iocp_io_service::stop(v4, (int)v3);
    v5 = boost::system::system_category();
    m_val = 0;
    v10.m_val = 0;
    v10.m_cat = v5;
  }
  if ( (m_val != 0 ? (unsigned int)vostok::memory::process_allocator::finalize_impl : 0) != 0 )
    boost::asio::detail::do_throw_error(&v10);
  return v2;
}
