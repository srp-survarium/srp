bool __cdecl boost::asio::ip::operator==(const boost::asio::ip::address *a1, const boost::asio::ip::address *a2)
{
  if ( a1->type_ != a2->type_ )
    return 0;
  if ( a1->type_ != ipv6 )
    return a1->ipv4_address_.addr_.S_un.S_addr == a2->ipv4_address_.addr_.S_un.S_addr;
  return !memcmp(&a1->ipv6_address_, &a2->ipv6_address_, 0x10u)
      && a1->ipv6_address_.scope_id_ == a2->ipv6_address_.scope_id_;
}
