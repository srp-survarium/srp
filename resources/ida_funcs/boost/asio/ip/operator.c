bool __cdecl boost::asio::ip::operator==(const boost::asio::ip::address *a1, const boost::asio::ip::address *a2)
{
  if ( a1->type_ != a2->type_ )
    return 0;
  if ( a1->type_ != ipv6 )
    return a1->ipv4_address_.addr_.S_un.S_addr == a2->ipv4_address_.addr_.S_un.S_addr;
  return !memcmp(&a1->ipv6_address_, &a2->ipv6_address_, 0x10u)
      && a1->ipv6_address_.scope_id_ == a2->ipv6_address_.scope_id_;
}


BOOL __cdecl boost::asio::ip::operator!=(
        const boost::asio::ip::basic_resolver_iterator<boost::asio::ip::tcp> *a,
        const boost::asio::ip::basic_resolver_iterator<boost::asio::ip::tcp> *b)
{
  bool v3; // [esp+3h] [ebp-9h]

  v3 = !a->values_.px && !b->values_.px || a->values_.px == b->values_.px && a->index_ == b->index_;
  return !v3;
}
