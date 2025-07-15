const boost::system::error_category *boost::system::_dynamic_initializer_for__errno_ecat___0()
{
  const boost::system::error_category *result; // eax

  result = boost::system::generic_category();
  errno_ecat_0 = result;
  return result;
}
