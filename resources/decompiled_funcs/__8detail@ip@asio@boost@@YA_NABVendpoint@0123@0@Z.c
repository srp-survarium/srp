char __cdecl boost::asio::ip::detail::operator==(
        boost::asio::ip::detail::endpoint *e1,
        boost::asio::ip::detail::endpoint *e2)
{
  const boost::asio::ip::address *v2; // eax
  int v3; // esi
  const boost::asio::ip::address *v5; // [esp-4h] [ebp-DCh]
  char v6; // [esp+4h] [ebp-D4h]
  boost::asio::ip::address v7; // [esp+A0h] [ebp-38h] BYREF
  boost::asio::ip::address result; // [esp+BCh] [ebp-1Ch] BYREF

  v5 = boost::asio::ip::detail::endpoint::address(e2, &result);
  v2 = boost::asio::ip::detail::endpoint::address(e1, &v7);
  v6 = 0;
  if ( boost::asio::ip::operator==(v2, v5) )
  {
    v3 = boost::asio::ip::detail::endpoint::port(e1);
    if ( v3 == boost::asio::ip::detail::endpoint::port(e2) )
      return 1;
  }
  return v6;
}
