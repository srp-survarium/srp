DWORD __thiscall boost::asio::detail::win_mutex::do_init(
        boost::asio::detail::win_mutex *this,
        boost::asio::detail::win_mutex *thisa)
{
  if ( InitializeCriticalSectionAndSpinCount(&thisa->crit_section_, 0x80000000) )
    return 0;
  else
    return GetLastError();
}
