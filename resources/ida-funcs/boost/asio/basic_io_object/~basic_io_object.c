void __usercall boost::asio::basic_io_object<boost::asio::deadline_timer_service<boost::posix_time::ptime,boost::asio::time_traits<boost::posix_time::ptime>>>::~basic_io_object<boost::asio::deadline_timer_service<boost::posix_time::ptime,boost::asio::time_traits<boost::posix_time::ptime>>>(
        boost::asio::basic_io_object<boost::asio::deadline_timer_service<boost::posix_time::ptime,boost::asio::time_traits<boost::posix_time::ptime> > > *this@<ecx>,
        int *a2@<eax>)
{
  int v3; // esi
  boost::asio::detail::op_queue<boost::asio::detail::timer_op> *v4; // ecx
  boost::system::error_code ec; // [esp+8h] [ebp-Ch] BYREF

  v3 = *a2;
  boost::system::system_category();
  boost::asio::detail::deadline_timer_service<boost::asio::time_traits<boost::posix_time::ptime>>::cancel(
    (boost::asio::detail::deadline_timer_service<boost::asio::time_traits<boost::posix_time::ptime> > *)(v3 + 20),
    (boost::asio::detail::deadline_timer_service<boost::asio::time_traits<boost::posix_time::ptime> >::implementation_type *)(a2 + 2),
    &ec);
  boost::asio::detail::op_queue<boost::asio::detail::timer_op>::~op_queue<boost::asio::detail::timer_op>(v4, a2 + 5);
}
