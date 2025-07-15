void vostok::core::finalize_console()
{
  HANDLE StdHandle; // eax
  HANDLE v1; // eax
  HANDLE v2; // eax

  if ( s_console_initialized )
  {
    StdHandle = GetStdHandle(0xFFFFFFF6);
    CloseHandle(StdHandle);
    v1 = GetStdHandle(0xFFFFFFF5);
    CloseHandle(v1);
    v2 = GetStdHandle(0xFFFFFFF4);
    CloseHandle(v2);
    FreeConsole();
  }
}
