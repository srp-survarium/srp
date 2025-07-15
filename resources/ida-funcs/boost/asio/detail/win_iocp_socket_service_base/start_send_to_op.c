void __userpurge boost::asio::detail::win_iocp_socket_service_base::start_send_to_op(
        boost::asio::detail::win_iocp_socket_service_base *this@<edi>,
        boost::asio::detail::win_iocp_operation *op@<eax>,
        boost::asio::detail::win_iocp_socket_service_base::base_implementation_type *impl,
        _WSABUF *buffers,
        DWORD buffer_count,
        const sockaddr *addr,
        int addrlen,
        int flags)
{
  SOCKET socket; // eax
  unsigned int Error; // eax
  boost::asio::detail::win_iocp_io_service *v11; // ecx

  InterlockedIncrement(&this->iocp_service_->outstanding_work_);
  socket = impl->socket_;
  if ( impl->socket_ == -1 )
  {
    boost::asio::detail::win_iocp_io_service::on_completion(this->iocp_service_, op, 0x2719u, 0);
  }
  else
  {
    impl = 0;
    addrlen = WSASendTo(socket, buffers, buffer_count, (LPDWORD)&impl, 0, addr, addrlen, op, 0);
    Error = WSAGetLastError();
    if ( Error == 1234 )
      Error = 10061;
    if ( !addrlen || Error == 997 )
      boost::asio::detail::win_iocp_io_service::on_pending(v11, (int)this->iocp_service_, op);
    else
      boost::asio::detail::win_iocp_io_service::on_completion(this->iocp_service_, op, Error, (unsigned int)impl);
  }
}
