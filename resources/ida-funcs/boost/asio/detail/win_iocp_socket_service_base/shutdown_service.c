void __usercall boost::asio::detail::win_iocp_socket_service_base::shutdown_service(
        boost::asio::detail::win_iocp_socket_service_base *this@<ecx>,
        boost::asio::detail::win_iocp_socket_service_base *a2@<edi>)
{
  boost::asio::detail::win_iocp_socket_service_base::base_implementation_type *i; // esi

  EnterCriticalSection(&a2->mutex_.crit_section_);
  for ( i = a2->impl_list_; i; i = i->next_ )
  {
    boost::system::system_category();
    boost::asio::detail::win_iocp_socket_service_base::close_for_destruction(a2, i);
  }
  LeaveCriticalSection(&a2->mutex_.crit_section_);
}
