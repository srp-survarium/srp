bool __thiscall boost::asio::ip::address::is_loopback(boost::asio::ip::address *this)
{
  if ( this->type_ )
    return boost::asio::ip::address_v6::is_loopback(&this->ipv6_address_);
  else
    return (ntohl(this->ipv4_address_.addr_.S_un.S_addr) & 0xFF000000) == 2130706432;
}
