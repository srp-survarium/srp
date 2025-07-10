const boost::system::error_category *boost::system::_dynamic_initializer_for__posix_category__()
{
  const boost::system::error_category *result; // eax

  result = boost::system::generic_category();
  posix_category = result;
  return result;
}
