boost::asio::ip::address_v6 *__thiscall boost::asio::ip::address::to_v6(
        boost::asio::ip::address *this,
        boost::asio::ip::address_v6 *result)
{
  std::bad_cast ex; // [esp+8h] [ebp-Ch] BYREF

  if ( this->type_ != ipv6 )
  {
    std::bad_cast::bad_cast(&ex, &stru_984D24.m_working_macro_list.m_buffer[1].m_store[404]);
    boost::throw_exception(&ex);
    std::bad_cast::~bad_cast(&ex);
  }
  *result = this->ipv6_address_;
  return result;
}
