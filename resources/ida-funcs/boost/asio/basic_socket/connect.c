void __thiscall boost::asio::basic_socket<boost::asio::ip::udp,boost::asio::datagram_socket_service<boost::asio::ip::udp>>::connect(
        boost::asio::basic_socket<boost::asio::ip::udp,boost::asio::datagram_socket_service<boost::asio::ip::udp> > *this,
        const boost::asio::ip::basic_endpoint<boost::asio::ip::udp> *peer_endpoint)
{
  boost::system::error_code result; // [esp+34Ch] [ebp-14h] BYREF
  boost::asio::ip::udp v4; // [esp+354h] [ebp-Ch] BYREF
  boost::system::error_code ec; // [esp+358h] [ebp-8h] BYREF

  ec.m_val = 0;
  ec.m_cat = boost::system::system_category();
  if ( this->implementation.socket_ == -1 )
  {
    v4.family_ = peer_endpoint->impl_.data_.base.sa_family == 2 ? 2 : 23;
    boost::asio::datagram_socket_service<boost::asio::ip::udp>::open(
      this->service,
      &result,
      &this->implementation,
      &v4,
      &ec);
    if ( (ec.m_val != 0
        ? (unsigned int)boost::intrusive::detail::destructor_impl<boost::intrusive::detail::generic_hook<boost::intrusive::get_set_node_algo<void *,0>,boost::intrusive::member_tag,1,0>>
        : 0) != 0 )
      boost::asio::detail::do_throw_error(&ec, "connect");
  }
  if ( peer_endpoint->impl_.data_.base.sa_family == 2 )
    boost::asio::detail::socket_ops::sync_connect(
      this->implementation.socket_,
      &peer_endpoint->impl_.data_.base,
      0x10u,
      &ec);
  else
    boost::asio::detail::socket_ops::sync_connect(
      this->implementation.socket_,
      &peer_endpoint->impl_.data_.base,
      0x1Cu,
      &ec);
  if ( (ec.m_val != 0
      ? (unsigned int)boost::intrusive::detail::destructor_impl<boost::intrusive::detail::generic_hook<boost::intrusive::get_set_node_algo<void *,0>,boost::intrusive::member_tag,1,0>>
      : 0) != 0 )
    boost::asio::detail::do_throw_error(&ec, "connect");
}
