void __thiscall boost::asio::ip::detail::endpoint::endpoint(boost::asio::ip::detail::endpoint *this)
{
  *(_QWORD *)&this->data_.base.sa_family = 0;
  *(_QWORD *)this->data_.v6.sin6_addr.u.Byte = 0;
  *(_QWORD *)&this->data_.v6.sin6_addr.u.Word[4] = 0;
  this->data_.v6.sin6_scope_id = 0;
  *(_QWORD *)&this->data_.base.sa_family = 2;
}
