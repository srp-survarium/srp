void __thiscall boost::asio::basic_socket<boost::asio::ip::tcp,boost::asio::stream_socket_service<boost::asio::ip::tcp>>::basic_socket<boost::asio::ip::tcp,boost::asio::stream_socket_service<boost::asio::ip::tcp>>(
        boost::asio::basic_socket<boost::asio::ip::tcp,boost::asio::stream_socket_service<boost::asio::ip::tcp> > *this,
        boost::asio::io_service *io_service)
{
  boost::asio::basic_io_object<boost::asio::stream_socket_service<boost::asio::ip::tcp>>::basic_io_object<boost::asio::stream_socket_service<boost::asio::ip::tcp>>(
    this,
    io_service);
}


void __thiscall boost::asio::basic_socket<boost::asio::ip::udp,boost::asio::datagram_socket_service<boost::asio::ip::udp>>::basic_socket<boost::asio::ip::udp,boost::asio::datagram_socket_service<boost::asio::ip::udp>>(
        boost::asio::basic_socket<boost::asio::ip::udp,boost::asio::datagram_socket_service<boost::asio::ip::udp> > *this,
        boost::asio::io_service *io_service,
        const boost::asio::ip::basic_endpoint<boost::asio::ip::udp> *endpoint)
{
  boost::system::error_code result; // [esp+2F0h] [ebp-28h] BYREF
  boost::asio::datagram_socket_service<boost::asio::ip::udp> *service; // [esp+2F8h] [ebp-20h]
  boost::system::error_code v6; // [esp+2FCh] [ebp-1Ch]
  boost::system::error_code v7; // [esp+304h] [ebp-14h]
  boost::asio::ip::udp protocol; // [esp+30Ch] [ebp-Ch] BYREF
  boost::system::error_code ec; // [esp+310h] [ebp-8h] BYREF

  this->service = boost::asio::detail::service_registry::use_service<boost::asio::datagram_socket_service<boost::asio::ip::udp>>(io_service->service_registry_);
  boost::asio::detail::win_iocp_socket_service<boost::asio::ip::udp>::implementation_type::implementation_type(&this->implementation);
  boost::asio::datagram_socket_service<boost::asio::ip::udp>::construct(this->service, &this->implementation);
  ec.m_val = 0;
  ec.m_cat = boost::system::system_category();
  if ( endpoint->impl_.data_.base.sa_family == 2 )
    protocol.family_ = 2;
  else
    protocol.family_ = 23;
  service = this->service;
  boost::asio::detail::win_iocp_socket_service<boost::asio::ip::udp>::open(
    &service->service_impl_,
    &result,
    &this->implementation,
    &protocol,
    &ec);
  v7 = ec;
  if ( (ec.m_val != 0
      ? (unsigned int)boost::intrusive::detail::destructor_impl<boost::intrusive::detail::generic_hook<boost::intrusive::get_set_node_algo<void *,0>,boost::intrusive::member_tag,1,0>>
      : 0) != 0 )
    boost::asio::detail::do_throw_error(&ec, "open");
  if ( endpoint->impl_.data_.base.sa_family == 2 )
    boost::asio::detail::socket_ops::bind(this->implementation.socket_, &endpoint->impl_.data_.base, 0x10u, &ec);
  else
    boost::asio::detail::socket_ops::bind(this->implementation.socket_, &endpoint->impl_.data_.base, 0x1Cu, &ec);
  v6 = ec;
  if ( (ec.m_val != 0
      ? (unsigned int)boost::intrusive::detail::destructor_impl<boost::intrusive::detail::generic_hook<boost::intrusive::get_set_node_algo<void *,0>,boost::intrusive::member_tag,1,0>>
      : 0) != 0 )
    boost::asio::detail::do_throw_error(&ec, "bind");
}
