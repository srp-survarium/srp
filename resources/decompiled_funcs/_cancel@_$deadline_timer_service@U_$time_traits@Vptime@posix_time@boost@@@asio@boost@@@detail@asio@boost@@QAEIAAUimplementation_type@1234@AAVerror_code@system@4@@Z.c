unsigned int __thiscall boost::asio::detail::deadline_timer_service<boost::asio::time_traits<boost::posix_time::ptime>>::cancel(
        boost::asio::detail::deadline_timer_service<boost::asio::time_traits<boost::posix_time::ptime> > *this,
        boost::asio::detail::deadline_timer_service<boost::asio::time_traits<boost::posix_time::ptime> >::implementation_type *impl,
        boost::system::error_code *ec)
{
  const boost::system::error_category *v4; // [esp+8h] [ebp-10h]
  const boost::system::error_category *v5; // [esp+10h] [ebp-8h]
  unsigned int count; // [esp+14h] [ebp-4h]

  if ( impl->might_have_pending_waits )
  {
    count = boost::asio::detail::win_iocp_io_service::cancel_timer<boost::asio::time_traits<boost::posix_time::ptime>>(
              this->scheduler_,
              &this->timer_queue_,
              &impl->timer_data,
              0xFFFFFFFF);
    impl->might_have_pending_waits = 0;
    v4 = boost::system::system_category();
    ec->m_val = 0;
    ec->m_cat = v4;
    return count;
  }
  else
  {
    v5 = boost::system::system_category();
    ec->m_val = 0;
    ec->m_cat = v5;
    return 0;
  }
}
