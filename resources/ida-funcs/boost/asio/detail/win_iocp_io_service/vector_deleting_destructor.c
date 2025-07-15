boost::asio::detail::win_iocp_io_service *__thiscall boost::asio::detail::win_iocp_io_service::`vector deleting destructor'(
        boost::asio::detail::win_iocp_io_service *this,
        char a2)
{
  boost::asio::detail::scoped_ptr<boost::asio::detail::win_thread> *v3; // ecx

  boost::asio::detail::op_queue<boost::asio::detail::win_iocp_operation>::~op_queue<boost::asio::detail::win_iocp_operation>(
    (boost::asio::detail::op_queue<boost::asio::detail::win_iocp_operation> *)this,
    (int *)&this->completed_ops_);
  DeleteCriticalSection(&this->dispatch_mutex_.crit_section_);
  if ( this->waitable_timer_.handle )
    CloseHandle(this->waitable_timer_.handle);
  boost::asio::detail::scoped_ptr<boost::asio::detail::win_thread>::~scoped_ptr<boost::asio::detail::win_thread>(
    v3,
    (HANDLE **)&this->timer_thread_);
  if ( this->iocp_.handle )
    CloseHandle(this->iocp_.handle);
  this->__vftable = (boost::asio::detail::win_iocp_io_service_vtbl *)&boost::asio::io_service::service::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
