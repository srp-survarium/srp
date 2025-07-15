const boost::system::error_category *boost::system::_dynamic_initializer_for__posix_category___1()
{
  const boost::system::error_category *result; // eax

  result = boost::system::generic_category();
  posix_category_1 = result;
  return result;
}
