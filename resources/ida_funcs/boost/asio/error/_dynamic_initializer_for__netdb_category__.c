const boost::system::error_category *boost::asio::error::_dynamic_initializer_for__netdb_category__()
{
  const boost::system::error_category *result; // eax

  result = boost::system::system_category();
  netdb_category = result;
  return result;
}
