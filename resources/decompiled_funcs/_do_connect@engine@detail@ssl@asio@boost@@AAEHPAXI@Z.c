int __thiscall boost::asio::ssl::detail::engine::do_connect(
        boost::asio::ssl::detail::engine *this,
        void *__formal,
        unsigned int a3)
{
  return SSL_connect(this->ssl_);
}
