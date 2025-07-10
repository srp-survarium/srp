int dynamic_initializer_for__boost::asio::ssl::detail::openssl_init_1_::instance___()
{
  unsigned __int8 dst[4]; // [esp+7Ch] [ebp-4h] BYREF

  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&boost::asio::ssl::detail::openssl_init<1>::instance_);
  boost::asio::ssl::detail::openssl_init_base::instance(&boost::asio::ssl::detail::openssl_init<1>::instance_.ref_);
  *(_DWORD *)dst = &boost::asio::ssl::detail::openssl_init<1>::instance_;
  memmove(dst, dst, 4u);
  return atexit(dynamic_atexit_destructor_for__boost::asio::ssl::detail::openssl_init_1_::instance___);
}
