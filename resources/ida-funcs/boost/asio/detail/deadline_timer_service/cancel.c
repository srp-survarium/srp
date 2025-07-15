unsigned int __usercall boost::asio::detail::deadline_timer_service<boost::asio::time_traits<boost::posix_time::ptime>>::cancel@<eax>(
        boost::asio::detail::deadline_timer_service<boost::asio::time_traits<boost::posix_time::ptime> > *this@<eax>,
        boost::asio::detail::deadline_timer_service<boost::asio::time_traits<boost::posix_time::ptime> >::implementation_type *impl@<ecx>,
        boost::system::error_code *ec@<esi>)
{
  unsigned int result; // eax
  unsigned int v5; // eax
  unsigned int v6; // ebx

  if ( impl->might_have_pending_waits )
  {
    v5 = boost::asio::detail::win_iocp_io_service::cancel_timer<boost::asio::time_traits<boost::posix_time::ptime>>(
           (boost::asio::detail::win_iocp_io_service *)&impl->timer_data,
           (_RTL_CRITICAL_SECTION *)this->scheduler_,
           &this->timer_queue_,
           &impl->timer_data,
           0xFFFFFFFF);
    impl->might_have_pending_waits = 0;
    v6 = v5;
    ec->m_cat = boost::system::system_category();
    result = v6;
  }
  else
  {
    ec->m_cat = boost::system::system_category();
    result = 0;
  }
  ec->m_val = 0;
  return result;
}
