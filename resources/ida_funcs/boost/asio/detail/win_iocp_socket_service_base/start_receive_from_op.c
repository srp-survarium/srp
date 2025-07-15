void __thiscall boost::asio::detail::win_iocp_socket_service_base::start_receive_from_op(
        boost::asio::detail::win_iocp_socket_service_base *this,
        boost::asio::detail::win_iocp_socket_service_base::base_implementation_type *impl,
        _WSABUF *buffers,
        DWORD buffer_count,
        sockaddr *addr,
        unsigned int flags,
        int *addrlen,
        boost::asio::detail::win_iocp_operation *op)
{
  int result; // [esp+5Ch] [ebp-10h]
  unsigned int recv_flags; // [esp+60h] [ebp-Ch] BYREF
  unsigned int last_error; // [esp+64h] [ebp-8h]
  unsigned int bytes_transferred; // [esp+68h] [ebp-4h] BYREF

  InterlockedIncrement(&this->iocp_service_->outstanding_work_);
  if ( impl->socket_ == -1 )
  {
    boost::asio::detail::win_iocp_io_service::on_completion(this->iocp_service_, op, 0x2719u, 0);
  }
  else
  {
    bytes_transferred = 0;
    recv_flags = flags;
    result = WSARecvFrom(impl->socket_, buffers, buffer_count, &bytes_transferred, &recv_flags, addr, addrlen, op, 0);
    last_error = WSAGetLastError();
    if ( last_error == 1234 )
      last_error = 10061;
    if ( !result || last_error == 997 )
      boost::asio::detail::win_iocp_io_service::on_pending(this->iocp_service_, op);
    else
      boost::asio::detail::win_iocp_io_service::on_completion(this->iocp_service_, op, last_error, bytes_transferred);
  }
}
