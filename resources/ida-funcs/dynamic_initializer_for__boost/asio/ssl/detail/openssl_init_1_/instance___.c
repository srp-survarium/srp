int __thiscall dynamic_initializer_for__boost::asio::ssl::detail::openssl_init_1_::instance___(
        boost::asio::ssl::detail::openssl_init<1> *this)
{
  boost::asio::ssl::detail::openssl_init<1>::openssl_init<1>(
    this,
    &boost::asio::ssl::detail::openssl_init<1>::instance_.ref_);
  return atexit(dynamic_atexit_destructor_for__boost::asio::ssl::detail::openssl_init_1_::instance___);
}
