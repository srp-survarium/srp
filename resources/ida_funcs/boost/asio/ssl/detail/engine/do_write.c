int __thiscall boost::asio::ssl::detail::engine::do_write(
        boost::asio::ssl::detail::engine *this,
        void *data,
        unsigned int length)
{
  if ( length >= 0x7FFFFFFF )
    return SSL_write(this->ssl_, data, 0x7FFFFFFF);
  else
    return SSL_write(this->ssl_, data, length);
}
