boost::asio::ip::address *__cdecl boost::asio::ip::address::from_string(
        boost::asio::ip::address *result,
        char *str,
        boost::system::error_code *ec)
{
  unsigned int v3; // ecx
  boost::system::error_code *v4; // edi
  bool v5; // zf
  __int64 v7; // [esp+14h] [ebp-30h]
  __int64 v8; // [esp+1Ch] [ebp-28h]
  __int64 v9; // [esp+30h] [ebp-14h] BYREF
  __int64 v10; // [esp+38h] [ebp-Ch]
  unsigned int v11; // [esp+40h] [ebp-4h] BYREF

  v9 = 0;
  v10 = 0;
  v11 = 0;
  if ( boost::asio::detail::socket_ops::inet_pton(23, str, &v9, &v11, ec) > 0 )
  {
    v3 = v11;
    v7 = v9;
    v8 = v10;
  }
  else
  {
    v7 = 0;
    v8 = 0;
    v3 = 0;
  }
  v4 = ec;
  if ( ec->m_val )
  {
    boost::asio::ip::address_v4::from_string((boost::asio::ip::address_v4 *)&ec, str, ec);
    v5 = v4->m_val == 0;
    result->type_ = ipv4;
    if ( v5 )
    {
      result->ipv4_address_.addr_.S_un.S_addr = (unsigned int)ec;
      result->ipv6_address_.scope_id_ = 0;
      *(_QWORD *)result->ipv6_address_.addr_.u.Byte = 0;
      *(_QWORD *)&result->ipv6_address_.addr_.u.Word[4] = 0;
    }
    else
    {
      result->ipv4_address_.addr_.S_un.S_addr = 0;
      *(_QWORD *)result->ipv6_address_.addr_.u.Byte = 0;
      *(_QWORD *)&result->ipv6_address_.addr_.u.Word[4] = 0;
      result->ipv6_address_.scope_id_ = 0;
    }
  }
  else
  {
    v9 = 0;
    v10 = 0;
    result->type_ = ipv6;
    result->ipv4_address_.addr_.S_un.S_addr = 0;
    *(_QWORD *)result->ipv6_address_.addr_.u.Byte = v7;
    *(_QWORD *)&result->ipv6_address_.addr_.u.Word[4] = v8;
    result->ipv6_address_.scope_id_ = v3;
  }
  return result;
}
