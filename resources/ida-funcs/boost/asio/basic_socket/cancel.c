void __thiscall boost::asio::basic_socket<boost::asio::ip::udp,boost::asio::datagram_socket_service<boost::asio::ip::udp>>::cancel(
        boost::asio::basic_socket<boost::asio::ip::udp,boost::asio::datagram_socket_service<boost::asio::ip::udp> > *this)
{
  boost::system::error_code result; // [esp+1D0h] [ebp-10h] BYREF
  boost::system::error_code ec; // [esp+1D8h] [ebp-8h] BYREF

  ec.m_val = 0;
  ec.m_cat = boost::system::system_category();
  boost::asio::detail::win_iocp_socket_service_base::cancel(
    &this->service->service_impl_,
    &result,
    &this->implementation,
    &ec);
  if ( (ec.m_val != 0
      ? (unsigned int)boost::intrusive::detail::destructor_impl<boost::intrusive::detail::generic_hook<boost::intrusive::get_set_node_algo<void *,0>,boost::intrusive::member_tag,1,0>>
      : 0) != 0 )
    boost::asio::detail::do_throw_error(&ec, "cancel");
}
