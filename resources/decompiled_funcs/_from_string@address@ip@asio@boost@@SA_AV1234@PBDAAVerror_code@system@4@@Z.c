boost::asio::ip::address *__cdecl boost::asio::ip::address::from_string(
        boost::asio::ip::address *result,
        char *str,
        boost::system::error_code *ec)
{
  __int64 dest; // [esp+1Ch] [ebp-7Ch] BYREF
  boost::asio::ip::address_v6 *p_ipv6_address; // [esp+24h] [ebp-74h]
  boost::asio::ip::address_v4 *p_ipv4_address; // [esp+28h] [ebp-70h]
  boost::asio::ip::address v7; // [esp+48h] [ebp-50h] BYREF
  boost::asio::ip::address tmp; // [esp+64h] [ebp-34h] BYREF
  boost::asio::ip::address_v4 ipv4_address; // [esp+80h] [ebp-18h]
  boost::asio::ip::address_v6 ipv6_address; // [esp+84h] [ebp-14h] BYREF

  boost::asio::ip::address_v6::from_string(&ipv6_address, str, ec);
  if ( ec->m_val )
  {
    LODWORD(dest) = 0;
    if ( boost::asio::detail::socket_ops::inet_pton(2, str, &dest, 0, ec) > 0 )
      ipv4_address = (boost::asio::ip::address_v4)dest;
    else
      ipv4_address = 0;
    if ( ec->m_val )
    {
      boost::asio::ip::address::address(result);
    }
    else
    {
      boost::asio::ip::address::address(&v7);
      v7.type_ = ipv4;
      v7.ipv4_address_ = ipv4_address;
      result->type_ = ipv4;
      result->ipv4_address_.addr_.S_un.S_addr = v7.ipv4_address_.addr_.S_un.S_addr;
      result->ipv6_address_ = v7.ipv6_address_;
    }
    return result;
  }
  else
  {
    boost::asio::ip::address::address(&tmp);
    tmp.type_ = ipv6;
    tmp.ipv6_address_ = ipv6_address;
    result->type_ = ipv6;
    p_ipv4_address = &result->ipv4_address_;
    result->ipv4_address_.addr_.S_un.S_addr = tmp.ipv4_address_.addr_.S_un.S_addr;
    HIDWORD(dest) = &tmp.ipv6_address_;
    p_ipv6_address = &result->ipv6_address_;
    *(_QWORD *)result->ipv6_address_.addr_.u.Byte = *(_QWORD *)tmp.ipv6_address_.addr_.u.Byte;
    *(_QWORD *)&result->ipv6_address_.addr_.u.Word[4] = *(_QWORD *)&tmp.ipv6_address_.addr_.u.Word[4];
    p_ipv6_address->scope_id_ = *(_DWORD *)(HIDWORD(dest) + 16);
    return result;
  }
}
