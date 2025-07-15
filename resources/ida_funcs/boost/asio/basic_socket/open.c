void __thiscall boost::asio::basic_socket<boost::asio::ip::udp,boost::asio::datagram_socket_service<boost::asio::ip::udp>>::open(
        boost::asio::basic_socket<boost::asio::ip::udp,boost::asio::datagram_socket_service<boost::asio::ip::udp> > *this,
        const boost::asio::ip::udp *protocol)
{
  boost::system::error_code result; // [esp+198h] [ebp-1Ch] BYREF
  boost::asio::datagram_socket_service<boost::asio::ip::udp> *service; // [esp+1A0h] [ebp-14h]
  boost::system::error_code v5; // [esp+1A4h] [ebp-10h]
  boost::system::error_code ec; // [esp+1ACh] [ebp-8h] BYREF

  ec.m_val = 0;
  ec.m_cat = boost::system::system_category();
  service = this->service;
  boost::asio::detail::win_iocp_socket_service<boost::asio::ip::udp>::open(
    &service->service_impl_,
    &result,
    &this->implementation,
    protocol,
    &ec);
  v5 = ec;
  if ( (ec.m_val != 0
      ? (unsigned int)boost::intrusive::detail::destructor_impl<boost::intrusive::detail::generic_hook<boost::intrusive::get_set_node_algo<void *,0>,boost::intrusive::member_tag,1,0>>
      : 0) != 0 )
    boost::asio::detail::do_throw_error(&ec, "open");
}
