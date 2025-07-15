int __thiscall boost::asio::ssl::detail::engine::do_accept(
        boost::asio::ssl::detail::engine *this,
        void *__formal,
        unsigned int a3)
{
  int v4; // edi

  EnterCriticalSection(&CriticalSection);
  v4 = SSL_accept(this->ssl_);
  LeaveCriticalSection(&CriticalSection);
  return v4;
}
