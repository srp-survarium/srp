int boost::asio::detail::_dynamic_initializer_for__winsock_init_instance__()
{
  int result; // eax

  atexit(dynamic_atexit_destructor_for___S3__);
  boost::asio::detail::winsock_init_base::startup(
    (boost::asio::detail::winsock_init_base::data *)&`boost::asio::error::get_misc_category'::`2'::`local static guard'.survarium::flash_external_handler,
    2u,
    0);
  result = 0;
  winsock_init_instance = &_S3_0;
  return result;
}
