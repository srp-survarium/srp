void __usercall boost::asio::detail::win_iocp_socket_service_base::construct(
        boost::asio::detail::win_iocp_socket_service_base *this@<edi>,
        boost::asio::detail::win_iocp_socket_service_base::base_implementation_type *impl@<esi>,
        boost::shared_ptr<void> *a3@<ecx>)
{
  boost::asio::detail::win_iocp_socket_service_base::base_implementation_type *impl_list; // eax
  boost::asio::detail::win_iocp_socket_service_base::base_implementation_type *v4; // eax

  impl->socket_ = -1;
  impl->state_ = 0;
  boost::shared_ptr<void>::reset(a3, &impl->cancel_token_.px);
  EnterCriticalSection(&this->mutex_.crit_section_);
  impl_list = this->impl_list_;
  impl->prev_ = 0;
  impl->next_ = impl_list;
  v4 = this->impl_list_;
  if ( v4 )
    v4->prev_ = impl;
  this->impl_list_ = impl;
  LeaveCriticalSection(&this->mutex_.crit_section_);
}
