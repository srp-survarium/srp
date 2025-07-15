boost::asio::ip::basic_endpoint<boost::asio::ip::tcp> *__thiscall boost::asio::detail::win_iocp_socket_service<boost::asio::ip::tcp>::remote_endpoint(
        boost::asio::detail::win_iocp_socket_service<boost::asio::ip::tcp> *this,
        boost::asio::ip::basic_endpoint<boost::asio::ip::tcp> *result,
        const boost::asio::detail::win_iocp_socket_service<boost::asio::ip::tcp>::implementation_type *impl,
        boost::system::error_code *ec)
{
  boost::asio::ip::basic_endpoint<boost::asio::ip::tcp> endpoint; // [esp+1B8h] [ebp-20h] BYREF
  unsigned int addr_len; // [esp+1D4h] [ebp-4h] BYREF

  qmemcpy(&endpoint, &impl->remote_endpoint_, sizeof(endpoint));
  addr_len = 28;
  if ( boost::asio::detail::socket_ops::getpeername(
         impl->socket_,
         &endpoint.impl_.data_.base,
         &addr_len,
         impl->have_remote_endpoint_,
         ec) )
  {
    *(_QWORD *)&result->impl_.data_.base.sa_family = 0;
    *(_QWORD *)result->impl_.data_.v6.sin6_addr.u.Byte = 0;
    *(_QWORD *)&result->impl_.data_.v6.sin6_addr.u.Word[4] = 0;
    result->impl_.data_.v6.sin6_scope_id = 0;
    *(_QWORD *)&result->impl_.data_.base.sa_family = 2;
  }
  else
  {
    boost::asio::ip::basic_endpoint<boost::asio::ip::tcp>::resize(
      (boost::asio::ip::basic_endpoint<boost::asio::ip::udp> *)&endpoint,
      addr_len);
    qmemcpy(result, &endpoint, sizeof(boost::asio::ip::basic_endpoint<boost::asio::ip::tcp>));
  }
  return result;
}
