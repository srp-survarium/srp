void __thiscall boost::asio::basic_socket<boost::asio::ip::udp,boost::asio::datagram_socket_service<boost::asio::ip::udp>>::bind(
        boost::asio::basic_socket<boost::asio::ip::udp,boost::asio::datagram_socket_service<boost::asio::ip::udp> > *this,
        const boost::asio::ip::basic_endpoint<boost::asio::ip::udp> *endpoint)
{
  boost::system::error_code ec; // [esp+198h] [ebp-8h] BYREF

  ec.m_val = 0;
  ec.m_cat = boost::system::system_category();
  if ( endpoint->impl_.data_.base.sa_family == 2 )
    boost::asio::detail::socket_ops::bind(this->implementation.socket_, &endpoint->impl_.data_.base, 0x10u, &ec);
  else
    boost::asio::detail::socket_ops::bind(this->implementation.socket_, &endpoint->impl_.data_.base, 0x1Cu, &ec);
  if ( (ec.m_val != 0
      ? (unsigned int)boost::intrusive::detail::destructor_impl<boost::intrusive::detail::generic_hook<boost::intrusive::get_set_node_algo<void *,0>,boost::intrusive::member_tag,1,0>>
      : 0) != 0 )
    boost::asio::detail::do_throw_error(&ec, "bind");
}
