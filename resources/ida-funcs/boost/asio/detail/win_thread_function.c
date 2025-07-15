unsigned int __stdcall boost::asio::detail::win_thread_function(HANDLE *a1)
{
  HANDLE v2; // ebx

  SetEvent(a1[1]);
  (*((void (__thiscall **)(HANDLE *))*a1 + 1))(a1);
  v2 = a1[2];
  (*(void (__thiscall **)(HANDLE *, int))*a1)(a1, 1);
  SetEvent(v2);
  SleepEx(0xFFFFFFFF, 1);
  return 0;
}
