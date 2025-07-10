void __thiscall boost::asio::detail::win_iocp_socket_service_base::start_send_op(
        boost::asio::detail::win_iocp_socket_service_base *this,
        boost::asio::detail::win_iocp_socket_service_base::base_implementation_type *impl,
        _WSABUF *buffers,
        DWORD buffer_count,
        DWORD flags,
        bool noop,
        boost::asio::detail::win_iocp_operation *op)
{
  int result; // [esp+74h] [ebp-Ch]
  int last_error; // [esp+78h] [ebp-8h]
  unsigned int bytes_transferred; // [esp+7Ch] [ebp-4h] BYREF

  InterlockedIncrement(&this->iocp_service_->outstanding_work_);
  if ( noop )
  {
    boost::asio::detail::win_iocp_io_service::on_completion(this->iocp_service_, op, 0, 0);
  }
  else if ( impl->socket_ == -1 )
  {
    boost::asio::detail::win_iocp_io_service::on_completion(this->iocp_service_, op, 0x2719u, 0);
  }
  else
  {
    bytes_transferred = 0;
    result = WSASend(impl->socket_, buffers, buffer_count, &bytes_transferred, flags, op, 0);
    last_error = WSAGetLastError();
    if ( last_error == 1234 )
      last_error = 10061;
    if ( !result || last_error == 997 )
      boost::asio::detail::win_iocp_io_service::on_pending(this->iocp_service_, op);
    else
      boost::asio::detail::win_iocp_io_service::on_completion(this->iocp_service_, op, last_error, bytes_transferred);
  }
}
