const boost::system::error_category *boost::asio::error::_dynamic_initializer_for__netdb_category___0()
{
  const boost::system::error_category *result; // eax

  result = boost::system::system_category();
  netdb_category_0 = result;
  return result;
}
