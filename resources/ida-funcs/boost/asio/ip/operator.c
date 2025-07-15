bool __usercall boost::asio::ip::operator==@<al>(
        const boost::asio::ip::address *a1@<eax>,
        const boost::asio::ip::address *a2@<ecx>)
{
  boost::asio::ip::address_v6 *p_ipv6_address; // edx
  boost::asio::ip::address_v6 *v4; // eax

  if ( a1->type_ != a2->type_ )
    return 0;
  if ( a1->type_ != ipv6 )
    return a2->ipv4_address_.addr_.S_un.S_addr == a1->ipv4_address_.addr_.S_un.S_addr;
  p_ipv6_address = &a2->ipv6_address_;
  v4 = &a1->ipv6_address_;
  return !memcmp(v4, &a2->ipv6_address_, 0x10u) && v4->scope_id_ == p_ipv6_address->scope_id_;
}


bool __usercall boost::asio::ip::operator!=@<al>(
        const boost::asio::ip::basic_resolver_iterator<boost::asio::ip::tcp> *a@<edx>,
        const boost::asio::ip::basic_resolver_iterator<boost::asio::ip::tcp> *b@<eax>)
{
  bool v2; // al

  v2 = !a->values_.px && !b->values_.px || a->values_.px == b->values_.px && a->index_ == b->index_;
  return !v2;
}
