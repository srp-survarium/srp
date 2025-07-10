const boost::system::error_category *boost::system::_dynamic_initializer_for__errno_ecat___8()
{
  const boost::system::error_category *result; // eax

  result = boost::system::generic_category();
  errno_ecat_8 = result;
  return result;
}
