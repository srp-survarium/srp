boost::system::error_code *__userpurge boost::asio::detail::win_iocp_socket_service<boost::asio::ip::tcp>::open@<eax>(
        boost::asio::detail::win_iocp_socket_service_base *impl@<ecx>,
        const boost::asio::ip::tcp *protocol@<eax>,
        boost::system::error_code *this,
        boost::system::error_code *ec,
        boost::system::error_code *a5)
{
  boost::system::error_code *result; // eax
  _DWORD v8[7]; // [esp+Ch] [ebp-28h] BYREF
  char v9; // [esp+28h] [ebp-Ch] BYREF

  if ( !boost::asio::detail::win_iocp_socket_service_base::do_open(
          impl,
          this,
          (boost::asio::detail::win_iocp_socket_service_base::base_implementation_type *)&v9,
          (int)impl,
          protocol->family_,
          (void *)1,
          (boost::system::error_code *)6,
          (int)a5)->socket_ )
  {
    impl->mutex_.crit_section_.LockSemaphore = (void *)protocol->family_;
    memset(v8, 0, sizeof(v8));
    LOWORD(v8[0]) = 2;
    LOBYTE(impl->mutex_.crit_section_.SpinCount) = 0;
    HIWORD(v8[0]) = 0;
    v8[1] = 0;
    qmemcpy(&impl->impl_list_, v8, 0x1Cu);
  }
  result = ec;
  *ec = *a5;
  return result;
}


boost::system::error_code *__userpurge boost::asio::detail::win_iocp_socket_service<boost::asio::ip::udp>::open@<eax>(
        boost::asio::detail::win_iocp_socket_service_base *impl@<ecx>,
        const boost::asio::ip::udp *protocol@<eax>,
        boost::system::error_code *this,
        boost::system::error_code *ec,
        boost::system::error_code *a5)
{
  boost::system::error_code *result; // eax
  _DWORD v8[7]; // [esp+Ch] [ebp-28h] BYREF
  char v9; // [esp+28h] [ebp-Ch] BYREF

  if ( !boost::asio::detail::win_iocp_socket_service_base::do_open(
          impl,
          this,
          (boost::asio::detail::win_iocp_socket_service_base::base_implementation_type *)&v9,
          (int)impl,
          protocol->family_,
          (void *)2,
          (boost::system::error_code *)0x11,
          (HANDLE)a5)->socket_ )
  {
    impl->mutex_.crit_section_.LockSemaphore = (void *)protocol->family_;
    memset(v8, 0, sizeof(v8));
    LOWORD(v8[0]) = 2;
    LOBYTE(impl->mutex_.crit_section_.SpinCount) = 0;
    HIWORD(v8[0]) = 0;
    v8[1] = 0;
    qmemcpy(&impl->impl_list_, v8, 0x1Cu);
  }
  result = ec;
  *ec = *a5;
  return result;
}
