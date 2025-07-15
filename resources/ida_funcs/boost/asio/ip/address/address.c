void __thiscall boost::asio::ip::address::address(boost::asio::ip::address *this)
{
  this->type_ = ipv4;
  this->ipv4_address_.addr_.S_un.S_addr = 0;
  *(_QWORD *)this->ipv6_address_.addr_.u.Byte = 0;
  *(_QWORD *)&this->ipv6_address_.addr_.u.Word[4] = 0;
  this->ipv6_address_.scope_id_ = 0;
}
