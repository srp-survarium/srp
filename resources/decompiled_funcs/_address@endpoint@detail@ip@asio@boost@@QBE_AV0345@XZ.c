boost::asio::ip::address *__thiscall boost::asio::ip::detail::endpoint::address(
        boost::asio::ip::detail::endpoint *this,
        boost::asio::ip::address *result)
{
  in_addr::<unnamed_type_S_un> v2; // eax
  u_long hostlong; // [esp+18h] [ebp-30h]
  boost::asio::ip::address_v6 v5; // [esp+20h] [ebp-28h]

  if ( this->data_.base.sa_family == 2 )
  {
    hostlong = ntohl(this->data_.v4.sin_addr.S_un.S_addr);
    v2.S_addr = htonl(hostlong);
    result->type_ = ipv4;
    result->ipv4_address_.addr_.S_un = v2;
    *(_QWORD *)result->ipv6_address_.addr_.u.Byte = 0;
    *(_QWORD *)&result->ipv6_address_.addr_.u.Word[4] = 0;
    result->ipv6_address_.scope_id_ = 0;
  }
  else
  {
    v5.scope_id_ = this->data_.v6.sin6_scope_id;
    *(_QWORD *)v5.addr_.u.Byte = *(_QWORD *)this->data_.v6.sin6_addr.u.Byte;
    *(_QWORD *)&v5.addr_.u.Word[4] = *(_QWORD *)&this->data_.v6.sin6_addr.u.Word[4];
    result->type_ = ipv6;
    result->ipv4_address_.addr_.S_un.S_addr = 0;
    result->ipv6_address_ = v5;
  }
  return result;
}
