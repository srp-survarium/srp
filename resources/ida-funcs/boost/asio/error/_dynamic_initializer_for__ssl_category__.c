boost::asio::error::detail::ssl_category *boost::asio::error::_dynamic_initializer_for__ssl_category__()
{
  boost::asio::error::detail::ssl_category *result; // eax

  result = boost::asio::error::get_ssl_category();
  ssl_category = result;
  return result;
}
