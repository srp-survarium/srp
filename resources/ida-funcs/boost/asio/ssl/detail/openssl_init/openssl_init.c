void __thiscall boost::asio::ssl::detail::openssl_init<1>::openssl_init<1>(
        boost::asio::ssl::detail::openssl_init<1> *this,
        boost::shared_ptr<boost::asio::ssl::detail::openssl_init_base::do_init> *result)
{
  unsigned __int8 dst[4]; // [esp+0h] [ebp-4h] BYREF

  boost::asio::ssl::detail::openssl_init_base::instance(result);
  *(_DWORD *)dst = &boost::asio::ssl::detail::openssl_init<1>::instance_;
  memmove(dst, dst, 4u);
}
