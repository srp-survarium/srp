unsigned int __stdcall boost::asio::detail::win_thread_function(HANDLE *arg)
{
  HANDLE exit_event; // [esp+20h] [ebp-4h]

  SetEvent(arg[1]);
  (*((void (__thiscall **)(HANDLE *))*arg + 1))(arg);
  exit_event = arg[2];
  if ( arg )
    (*(void (__thiscall **)(HANDLE *, int))*arg)(arg, 1);
  SetEvent(exit_event);
  SleepEx(0xFFFFFFFF, 1);
  return 0;
}
