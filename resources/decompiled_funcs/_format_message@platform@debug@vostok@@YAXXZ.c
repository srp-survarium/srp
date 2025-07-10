void __cdecl vostok::debug::platform::format_message()
{
  char _Dest[4096]; // [esp+0h] [ebp-1010h] BYREF
  char Buffer[4]; // [esp+1004h] [ebp-Ch] BYREF
  DWORD dwMessageId; // [esp+1008h] [ebp-8h]
  void (__cdecl *log_callback)(const char *, bool, bool, const char *); // [esp+100Ch] [ebp-4h]

  dwMessageId = GetLastError();
  if ( dwMessageId )
  {
    *(_DWORD *)Buffer = 0;
    FormatMessageA(0x1100u, 0, dwMessageId, 0x400u, Buffer, 0, 0);
    log_callback = vostok::debug::get_log_callback();
    if ( log_callback )
    {
      sprintf_s<4096>((char (*)[4096])_Dest, "%d: %s", dwMessageId, *(const char **)Buffer);
      log_callback("debug", 1, 0, _Dest);
    }
    LocalFree(*(HLOCAL *)Buffer);
  }
}
