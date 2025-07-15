BOOL _get_printf_count_output()
{
  return _enable_percent_n == (__security_cookie | 1);
}
