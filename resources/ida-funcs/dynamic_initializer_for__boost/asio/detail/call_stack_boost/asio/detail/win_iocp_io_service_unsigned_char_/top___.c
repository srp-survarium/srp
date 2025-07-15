int dynamic_initializer_for__boost::asio::detail::call_stack_boost::asio::detail::win_iocp_io_service_unsigned_char_::top___()
{
  boost::asio::detail::call_stack<boost::asio::detail::win_iocp_io_service,unsigned char>::top_.tss_key_ = boost::asio::detail::win_tss_ptr_create();
  return atexit(dynamic_atexit_destructor_for__boost::asio::detail::call_stack_boost::asio::detail::win_iocp_io_service_unsigned_char_::top___);
}
