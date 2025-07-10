void __thiscall boost::asio::ip::detail::endpoint::endpoint(
        boost::asio::ip::detail::endpoint *this,
        int family,
        u_short port_num)
{
  *(_QWORD *)&this->data_.base.sa_family = 0;
  *(_QWORD *)this->data_.v6.sin6_addr.u.Byte = 0;
  *(_QWORD *)&this->data_.v6.sin6_addr.u.Word[4] = 0;
  this->data_.v6.sin6_scope_id = 0;
  if ( family == 2 )
  {
    this->data_.base.sa_family = 2;
    this->data_.v4.sin_port = htons(port_num);
    this->data_.v4.sin_addr.S_un.S_addr = 0;
  }
  else
  {
    this->data_.base.sa_family = 23;
    this->data_.v4.sin_port = htons(port_num);
    this->data_.v4.sin_addr.S_un.S_addr = 0;
    this->data_.base.sa_data[6] = 0;
    this->data_.base.sa_data[7] = 0;
    this->data_.base.sa_data[8] = 0;
    this->data_.base.sa_data[9] = 0;
    this->data_.base.sa_data[10] = 0;
    this->data_.base.sa_data[11] = 0;
    this->data_.base.sa_data[12] = 0;
    this->data_.base.sa_data[13] = 0;
    this->data_.v6.sin6_addr.u.Byte[8] = 0;
    this->data_.v6.sin6_addr.u.Byte[9] = 0;
    this->data_.v6.sin6_addr.u.Byte[10] = 0;
    this->data_.v6.sin6_addr.u.Byte[11] = 0;
    this->data_.v6.sin6_addr.u.Byte[12] = 0;
    this->data_.v6.sin6_addr.u.Byte[13] = 0;
    this->data_.v6.sin6_addr.u.Byte[14] = 0;
    this->data_.v6.sin6_addr.u.Byte[15] = 0;
    this->data_.v6.sin6_scope_id = 0;
  }
}
