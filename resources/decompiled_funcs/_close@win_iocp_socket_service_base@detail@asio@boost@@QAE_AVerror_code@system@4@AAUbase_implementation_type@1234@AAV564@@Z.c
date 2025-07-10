boost::system::error_code *__thiscall boost::asio::detail::win_iocp_socket_service_base::close(
        boost::asio::detail::win_iocp_socket_service_base *this,
        boost::system::error_code *result,
        boost::asio::detail::win_iocp_socket_service_base::base_implementation_type *impl,
        boost::system::error_code *ec)
{
  const boost::system::error_category *m_cat; // eax
  boost::asio::detail::select_reactor *r; // [esp+110h] [ebp-4h]

  if ( impl->socket_ != -1 )
  {
    r = (boost::asio::detail::select_reactor *)InterlockedCompareExchange((volatile LONG *)&this->reactor_, 0, 0);
    if ( r )
      boost::asio::detail::select_reactor::deregister_descriptor(r, impl->socket_, &impl->reactor_data_, 1);
  }
  boost::asio::detail::socket_ops::close(impl->socket_, &impl->state_, 0, ec);
  impl->socket_ = -1;
  impl->state_ = 0;
  boost::shared_ptr<void>::reset(&impl->cancel_token_);
  m_cat = ec->m_cat;
  result->m_val = ec->m_val;
  result->m_cat = m_cat;
  return result;
}
