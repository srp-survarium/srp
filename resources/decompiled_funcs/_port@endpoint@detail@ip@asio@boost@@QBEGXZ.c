u_short __thiscall boost::asio::ip::detail::endpoint::port(boost::asio::ip::detail::endpoint *this)
{
  return ntohs(this->data_.v4.sin_port);
}
