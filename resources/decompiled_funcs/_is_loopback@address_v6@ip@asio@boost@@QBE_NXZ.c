bool __thiscall boost::asio::ip::address_v6::is_loopback(boost::asio::ip::address_v6 *this)
{
  return !this->addr_.u.Byte[0]
      && !this->addr_.u.Byte[1]
      && !this->addr_.u.Byte[2]
      && !this->addr_.u.Byte[3]
      && !this->addr_.u.Byte[4]
      && !this->addr_.u.Byte[5]
      && !this->addr_.u.Byte[6]
      && !this->addr_.u.Byte[7]
      && !this->addr_.u.Byte[8]
      && !this->addr_.u.Byte[9]
      && !this->addr_.u.Byte[10]
      && !this->addr_.u.Byte[11]
      && !this->addr_.u.Byte[12]
      && !this->addr_.u.Byte[13]
      && !this->addr_.u.Byte[14]
      && this->addr_.u.Byte[15] == 1;
}
