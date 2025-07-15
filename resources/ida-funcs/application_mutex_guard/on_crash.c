void __thiscall application_mutex_guard::on_crash(application_mutex_guard *this)
{
  if ( s_mutex_1 )
  {
    CloseHandle(s_mutex_1);
    s_mutex_1 = 0;
  }
}
