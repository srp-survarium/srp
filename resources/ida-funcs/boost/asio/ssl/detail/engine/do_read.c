int __thiscall boost::asio::ssl::detail::engine::do_read(
        boost::asio::ssl::detail::engine *this,
        void *data,
        int length)
{
  return SSL_read(this->ssl_);
}
