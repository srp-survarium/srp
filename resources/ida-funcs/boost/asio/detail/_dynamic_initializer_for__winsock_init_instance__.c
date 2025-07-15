void boost::asio::detail::_dynamic_initializer_for__winsock_init_instance__()
{
  boost::asio::detail::winsock_init<2,0> *v0; // [esp-4h] [ebp-8h]

  atexit((int (__cdecl *)())dynamic_atexit_destructor_for___S5__);
  boost::asio::detail::winsock_init<2,0>::winsock_init<2,0>(v0, (bool)&_S5_0, 0);
  winsock_init_instance = &_S5_0;
}
