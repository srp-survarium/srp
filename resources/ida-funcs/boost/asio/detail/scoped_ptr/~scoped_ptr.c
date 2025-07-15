void __usercall boost::asio::detail::scoped_ptr<boost::asio::io_service>::~scoped_ptr<boost::asio::io_service>(
        boost::asio::detail::scoped_ptr<boost::asio::io_service> *this@<ecx>,
        _DWORD **a2@<eax>)
{
  _DWORD *v3; // edi
  _RTL_CRITICAL_SECTION *v4; // esi

  v3 = *a2;
  if ( *a2 )
  {
    v4 = (_RTL_CRITICAL_SECTION *)v3[1];
    if ( v4 )
      boost::asio::detail::service_registry::`scalar deleting destructor'(
        (boost::asio::detail::service_registry *)this,
        v4);
    boost::asio::detail::winsock_init<2,0>::~winsock_init<2,0>((boost::asio::detail::winsock_init<2,0> *)this);
    operator delete(v3);
  }
}


void __usercall boost::asio::detail::scoped_ptr<boost::asio::detail::win_thread>::~scoped_ptr<boost::asio::detail::win_thread>(
        boost::asio::detail::scoped_ptr<boost::asio::detail::win_thread> *this@<ecx>,
        HANDLE **a2@<eax>)
{
  HANDLE *v2; // esi

  v2 = *a2;
  if ( *a2 )
  {
    CloseHandle(v2[1]);
    operator delete(v2);
  }
}
