const boost::system::error_category *boost::asio::error::_dynamic_initializer_for__addrinfo_category__()
{
  const boost::system::error_category *result; // eax

  result = boost::system::system_category();
  addrinfo_category = result;
  return result;
}
