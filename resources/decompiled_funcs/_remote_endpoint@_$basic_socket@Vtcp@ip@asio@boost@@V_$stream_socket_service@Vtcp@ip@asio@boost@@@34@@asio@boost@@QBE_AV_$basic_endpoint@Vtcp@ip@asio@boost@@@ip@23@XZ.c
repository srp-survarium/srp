boost::asio::ip::basic_endpoint<boost::asio::ip::tcp> *__thiscall boost::asio::basic_socket<boost::asio::ip::tcp,boost::asio::stream_socket_service<boost::asio::ip::tcp>>::remote_endpoint(
        boost::asio::basic_socket<boost::asio::ip::tcp,boost::asio::stream_socket_service<boost::asio::ip::tcp> > *this,
        boost::asio::ip::basic_endpoint<boost::asio::ip::tcp> *result)
{
  boost::asio::ip::basic_endpoint<boost::asio::ip::tcp> ep; // [esp+1C8h] [ebp-24h] BYREF
  boost::system::error_code ec; // [esp+1E4h] [ebp-8h] BYREF

  ec.m_val = 0;
  ec.m_cat = boost::system::system_category();
  boost::asio::detail::win_iocp_socket_service<boost::asio::ip::tcp>::remote_endpoint(
    &this->service->service_impl_,
    &ep,
    &this->implementation,
    &ec);
  if ( (ec.m_val != 0
      ? (unsigned int)boost::intrusive::detail::destructor_impl<boost::intrusive::detail::generic_hook<boost::intrusive::get_set_node_algo<void *,0>,boost::intrusive::member_tag,1,0>>
      : 0) != 0 )
    boost::asio::detail::do_throw_error(&ec, "remote_endpoint");
  qmemcpy(result, &ep, sizeof(boost::asio::ip::basic_endpoint<boost::asio::ip::tcp>));
  return result;
}
