void __usercall boost::asio::detail::win_iocp_socket_service_base::close_for_destruction(
        boost::asio::detail::win_iocp_socket_service_base *this@<eax>,
        boost::asio::detail::win_iocp_socket_service_base::base_implementation_type *impl@<esi>)
{
  _RTL_CRITICAL_SECTION *v2; // eax
  boost::asio::detail::select_reactor *v3; // ecx
  const boost::system::error_category *v4; // eax
  boost::shared_ptr<void> *v5; // ecx
  unsigned int socket; // [esp-Ch] [ebp-1Ch]
  boost::asio::detail::select_reactor::per_descriptor_data *v7; // [esp+0h] [ebp-10h]
  bool v8; // [esp+4h] [ebp-Ch]
  boost::system::error_code v9; // [esp+8h] [ebp-8h] BYREF

  if ( impl->socket_ != -1 )
  {
    v2 = (_RTL_CRITICAL_SECTION *)InterlockedCompareExchange((volatile LONG *)&this->reactor_, 0, 0);
    if ( v2 )
      boost::asio::detail::select_reactor::deregister_descriptor(
        v3,
        v2,
        (stlp_std::priv::_List_node_base *)impl->socket_,
        v7,
        v8);
  }
  v9.m_val = 0;
  v4 = boost::system::system_category();
  socket = impl->socket_;
  v9.m_cat = v4;
  boost::asio::detail::socket_ops::close(&v9, socket, &impl->state_, 1);
  impl->socket_ = -1;
  impl->state_ = 0;
  boost::shared_ptr<void>::reset(v5, &impl->cancel_token_.px);
}
