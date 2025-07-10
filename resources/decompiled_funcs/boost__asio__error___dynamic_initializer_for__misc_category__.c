boost::asio::error::detail::misc_category *boost::asio::error::_dynamic_initializer_for__misc_category__()
{
  boost::asio::error::detail::misc_category *result; // eax

  result = boost::asio::error::get_misc_category();
  misc_category = result;
  return result;
}
