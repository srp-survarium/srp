void __thiscall boost::asio::detail::win_iocp_socket_service<boost::asio::ip::udp>::implementation_type::implementation_type(
        boost::asio::detail::win_iocp_socket_service<boost::asio::ip::udp>::implementation_type *this)
{
  this->cancel_token_.px = 0;
  this->cancel_token_.pn.pi_ = 0;
  this->protocol_.family_ = 2;
  this->have_remote_endpoint_ = 0;
  *(_QWORD *)&this->remote_endpoint_.impl_.data_.base.sa_family = 0;
  *(_QWORD *)this->remote_endpoint_.impl_.data_.v6.sin6_addr.u.Byte = 0;
  *(_QWORD *)&this->remote_endpoint_.impl_.data_.v6.sin6_addr.u.Word[4] = 0;
  this->remote_endpoint_.impl_.data_.v6.sin6_scope_id = 0;
  *(_QWORD *)&this->remote_endpoint_.impl_.data_.base.sa_family = 2;
}
