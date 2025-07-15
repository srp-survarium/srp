boost::system::error_code *__userpurge boost::asio::detail::win_iocp_socket_service_base::close@<eax>(
        boost::asio::detail::win_iocp_socket_service_base *this@<eax>,
        boost::asio::detail::win_iocp_socket_service_base::base_implementation_type *impl@<esi>,
        boost::system::error_code *ec,
        boost::system::error_code *a4)
{
  _RTL_CRITICAL_SECTION *v4; // eax
  boost::asio::detail::select_reactor *v5; // ecx
  boost::shared_ptr<void> *v6; // ecx
  boost::system::error_code *result; // eax
  boost::asio::detail::select_reactor::per_descriptor_data *v8; // [esp+0h] [ebp-Ch]
  bool v9; // [esp+4h] [ebp-8h]

  if ( impl->socket_ != -1 )
  {
    v4 = (_RTL_CRITICAL_SECTION *)InterlockedCompareExchange((volatile LONG *)&this->reactor_, 0, 0);
    if ( v4 )
      boost::asio::detail::select_reactor::deregister_descriptor(
        v5,
        v4,
        (stlp_std::priv::_List_node_base *)impl->socket_,
        v8,
        v9);
  }
  boost::asio::detail::socket_ops::close(a4, impl->socket_, &impl->state_, 0);
  impl->socket_ = -1;
  impl->state_ = 0;
  boost::shared_ptr<void>::reset(v6, &impl->cancel_token_.px);
  result = ec;
  *ec = *a4;
  return result;
}
