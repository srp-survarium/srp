void __thiscall boost::asio::detail::socket_select_interrupter::interrupt(
        boost::asio::detail::socket_select_interrupter *this)
{
  char byte; // [esp+4Bh] [ebp-11h] BYREF
  _WSABUF b; // [esp+4Ch] [ebp-10h] BYREF
  boost::system::error_code ec; // [esp+54h] [ebp-8h] BYREF

  byte = 0;
  b.buf = &byte;
  b.len = 1;
  ec.m_val = 0;
  ec.m_cat = boost::system::system_category();
  boost::asio::detail::socket_ops::send(this->write_descriptor_, &b, 1u, 0, &ec);
}
