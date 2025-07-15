int __stdcall WinMain(HINSTANCE__ *hInstance, HINSTANCE__ *hPrevInstance, char *lpCmdLine, int nCmdShow)
{
  if ( !check_presence_mutex() )
    return 1;
  vostok::debug::protected_call((void (__cdecl *)(void *))main_protected, 0);
  CloseHandle(s_presence_mutex);
  return s_exit_code;
}
