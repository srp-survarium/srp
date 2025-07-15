void __thiscall boost::asio::detail::socket_select_interrupter::interrupt(
        boost::asio::detail::socket_select_interrupter *this,
        int a2)
{
  boost::system::error_code v2; // [esp+4h] [ebp-18h] BYREF
  _WSABUF v3; // [esp+Ch] [ebp-10h] BYREF
  char v4; // [esp+17h] [ebp-5h] BYREF

  v2.m_val = 0;
  v4 = 0;
  v3.buf = &v4;
  v3.len = 1;
  v2.m_cat = boost::system::system_category();
  boost::asio::detail::socket_ops::send(&v2, *(_DWORD *)(a2 + 4), &v3, 1u);
}
