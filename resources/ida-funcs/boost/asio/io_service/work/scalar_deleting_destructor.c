int *__usercall boost::asio::io_service::work::`scalar deleting destructor'@<eax>(
        boost::asio::io_service::work *this@<ecx>,
        int *a2@<edi>)
{
  int v2; // esi
  boost::asio::detail::win_iocp_io_service *v3; // ecx

  v2 = *a2;
  if ( !InterlockedDecrement((volatile LONG *)(*a2 + 24)) )
    boost::asio::detail::win_iocp_io_service::stop(v3, v2);
  operator delete(a2);
  return a2;
}
