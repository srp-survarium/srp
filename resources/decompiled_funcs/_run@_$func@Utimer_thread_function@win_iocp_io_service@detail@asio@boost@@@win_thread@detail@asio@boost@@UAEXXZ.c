void __thiscall boost::asio::detail::win_thread::func<boost::asio::detail::win_iocp_io_service::timer_thread_function>::run(
        boost::asio::detail::win_thread::func<boost::asio::detail::win_iocp_io_service::timer_thread_function> *this)
{
  boost::asio::detail::win_iocp_io_service::timer_thread_function::operator()(&this->f_);
}
