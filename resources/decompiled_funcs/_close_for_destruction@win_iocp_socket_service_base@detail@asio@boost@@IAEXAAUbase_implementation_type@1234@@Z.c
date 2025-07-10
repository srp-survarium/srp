void __thiscall boost::asio::detail::win_iocp_socket_service_base::close_for_destruction(
        boost::asio::detail::win_iocp_socket_service_base *this,
        boost::asio::detail::win_iocp_socket_service_base::base_implementation_type *impl)
{
  boost::asio::detail::select_reactor *r; // [esp+110h] [ebp-Ch]
  boost::system::error_code ignored_ec; // [esp+114h] [ebp-8h] BYREF

  if ( impl->socket_ != -1 )
  {
    r = (boost::asio::detail::select_reactor *)InterlockedCompareExchange((volatile LONG *)&this->reactor_, 0, 0);
    if ( r )
      boost::asio::detail::select_reactor::deregister_descriptor(r, impl->socket_, &impl->reactor_data_, 1);
  }
  ignored_ec.m_val = 0;
  ignored_ec.m_cat = boost::system::system_category();
  boost::asio::detail::socket_ops::close(impl->socket_, &impl->state_, 1, &ignored_ec);
  impl->socket_ = -1;
  impl->state_ = 0;
  boost::shared_ptr<void>::reset(&impl->cancel_token_);
}
