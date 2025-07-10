boost::asio::detail::select_reactor *__thiscall boost::asio::detail::win_iocp_socket_service_base::get_reactor(
        boost::asio::detail::win_iocp_socket_service_base *this)
{
  boost::asio::detail::select_reactor *r; // [esp+8h] [ebp-4h]

  r = (boost::asio::detail::select_reactor *)InterlockedCompareExchange((volatile LONG *)&this->reactor_, 0, 0);
  if ( !r )
  {
    r = boost::asio::detail::service_registry::use_service<boost::asio::detail::select_reactor>(this->io_service_->service_registry_);
    InterlockedExchange((volatile LONG *)&this->reactor_, (LONG)r);
  }
  return r;
}
