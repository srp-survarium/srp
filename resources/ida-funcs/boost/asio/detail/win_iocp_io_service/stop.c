void __usercall boost::asio::detail::win_iocp_io_service::stop(
        boost::asio::detail::win_iocp_io_service *this@<ecx>,
        int a2@<eax>)
{
  boost::system::error_code err; // [esp+8h] [ebp-8h] BYREF

  if ( !InterlockedExchange((volatile LONG *)(a2 + 28), 1) && !PostQueuedCompletionStatus(*(HANDLE *)(a2 + 20), 0, 0, 0) )
  {
    err.m_val = GetLastError();
    err.m_cat = boost::system::system_category();
    if ( (err.m_val != 0 ? (unsigned int)vostok::memory::process_allocator::finalize_impl : 0) != 0 )
      boost::asio::detail::do_throw_error(&err, "pqcs");
  }
}
