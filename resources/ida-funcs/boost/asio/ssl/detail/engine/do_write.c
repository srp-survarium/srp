int __thiscall boost::asio::ssl::detail::engine::do_write(
        boost::asio::ssl::detail::engine *this,
        void *data,
        int length)
{
  return SSL_write(this->ssl_);
}
