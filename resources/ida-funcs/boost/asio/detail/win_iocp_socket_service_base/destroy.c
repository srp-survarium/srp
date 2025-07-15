void __usercall boost::asio::detail::win_iocp_socket_service_base::destroy(
        boost::asio::detail::win_iocp_socket_service_base *this@<edi>,
        boost::asio::detail::win_iocp_socket_service_base::base_implementation_type *impl@<eax>)
{
  boost::asio::detail::win_iocp_socket_service_base::base_implementation_type *prev; // eax
  boost::asio::detail::win_iocp_socket_service_base::base_implementation_type *next; // eax

  boost::asio::detail::win_iocp_socket_service_base::close_for_destruction(this, impl);
  EnterCriticalSection(&this->mutex_.crit_section_);
  if ( this->impl_list_ == impl )
    this->impl_list_ = impl->next_;
  prev = impl->prev_;
  if ( prev )
    prev->next_ = impl->next_;
  next = impl->next_;
  if ( next )
    next->prev_ = impl->prev_;
  impl->next_ = 0;
  impl->prev_ = 0;
  LeaveCriticalSection(&this->mutex_.crit_section_);
}
