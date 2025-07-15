void __userpurge boost::asio::detail::win_iocp_socket_service_base::start_send_op(
        boost::asio::detail::win_iocp_socket_service_base *this@<edi>,
        boost::asio::detail::win_iocp_operation *op@<eax>,
        boost::asio::detail::win_iocp_socket_service_base::base_implementation_type *impl,
        _WSABUF *buffers,
        unsigned int buffer_count,
        int flags,
        unsigned int noop)
{
  unsigned int socket; // eax
  unsigned int Error; // eax
  boost::asio::detail::win_iocp_io_service *v10; // ecx
  int v11; // [esp+10h] [ebp+8h]

  InterlockedIncrement(&this->iocp_service_->outstanding_work_);
  if ( (_BYTE)noop )
  {
    boost::asio::detail::win_iocp_io_service::on_completion(this->iocp_service_, op, 0, 0);
  }
  else
  {
    socket = impl->socket_;
    if ( impl->socket_ == -1 )
    {
      boost::asio::detail::win_iocp_io_service::on_completion(this->iocp_service_, op, 0x2719u, 0);
    }
    else
    {
      noop = 0;
      v11 = ((int (__stdcall *)(unsigned int, _WSABUF *, unsigned int, unsigned int *, int))(&off_8E3A98 + 25))(
              socket,
              buffers,
              buffer_count,
              &noop,
              flags);
      Error = WSAGetLastError();
      if ( Error == 1234 )
        Error = 10061;
      if ( !v11 || Error == 997 )
        boost::asio::detail::win_iocp_io_service::on_pending(v10, (int)this->iocp_service_, op);
      else
        boost::asio::detail::win_iocp_io_service::on_completion(this->iocp_service_, op, Error, noop);
    }
  }
}
