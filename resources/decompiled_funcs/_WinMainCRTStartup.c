int __cdecl WinMainCRTStartup()
{
  __security_init_cookie();
  return _tmainCRTStartup();
}
