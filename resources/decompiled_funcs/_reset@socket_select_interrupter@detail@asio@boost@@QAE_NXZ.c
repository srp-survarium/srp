bool __thiscall boost::asio::detail::socket_select_interrupter::reset(
        boost::asio::detail::socket_select_interrupter *this)
{
  char data[1024]; // [esp+8Ch] [ebp-418h] BYREF
  int bytes_read; // [esp+48Ch] [ebp-18h]
  _WSABUF b; // [esp+490h] [ebp-14h] BYREF
  boost::system::error_code ec; // [esp+498h] [ebp-Ch] BYREF
  bool was_interrupted; // [esp+4A3h] [ebp-1h]

  b.buf = data;
  b.len = 1024;
  ec.m_val = 0;
  ec.m_cat = boost::system::system_category();
  bytes_read = boost::asio::detail::socket_ops::recv(this->read_descriptor_, &b, 1u, 0, &ec);
  was_interrupted = bytes_read > 0;
  while ( bytes_read == 1024 )
    bytes_read = boost::asio::detail::socket_ops::recv(this->read_descriptor_, &b, 1u, 0, &ec);
  return was_interrupted;
}
