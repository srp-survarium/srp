void __thiscall boost::asio::basic_io_object<boost::asio::datagram_socket_service<boost::asio::ip::udp>>::~basic_io_object<boost::asio::datagram_socket_service<boost::asio::ip::udp>>(
        boost::asio::basic_io_object<boost::asio::datagram_socket_service<boost::asio::ip::udp> > *this)
{
  boost::asio::detail::win_iocp_socket_service_base::destroy(&this->service->service_impl_, &this->implementation);
  if ( this->implementation.cancel_token_.pn.pi_ )
    boost::detail::sp_counted_base::release(this->implementation.cancel_token_.pn.pi_);
}
