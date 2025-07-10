DWORD __thiscall boost::asio::detail::win_mutex::do_init(boost::asio::detail::win_mutex *this)
{
  if ( InitializeCriticalSectionAndSpinCount(&this->crit_section_, 0x80000000) )
    return 0;
  else
    return GetLastError();
}
