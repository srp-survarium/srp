DWORD __cdecl boost::asio::detail::win_tss_ptr_create()
{
  DWORD v0; // edi
  boost::system::error_code err; // [esp+4h] [ebp-8h] BYREF

  v0 = TlsAlloc();
  if ( v0 == -1 )
  {
    err.m_val = GetLastError();
    err.m_cat = boost::system::system_category();
    if ( (err.m_val != 0 ? (unsigned int)vostok::memory::process_allocator::finalize_impl : 0) != 0 )
      boost::asio::detail::do_throw_error(&err, "tss");
  }
  return v0;
}
