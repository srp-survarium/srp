void __cdecl process(char *index, unsigned int count, const char **strings)
{
  unsigned int v3; // ebx
  void *v4; // esp
  int v5; // esi
  _BYTE *v6; // eax
  const char *v7; // ecx
  _BYTE *v8; // eax
  char v9; // [esp+0h] [ebp-Ch] BYREF
  _BYTE v10[3]; // [esp+1h] [ebp-Bh] BYREF

  v3 = count;
  v4 = alloca(1028 * count + 1);
  v5 = 0;
  v9 = 91;
  v6 = v10;
  if ( count )
  {
    while ( 1 )
    {
      v7 = strings[v5];
      count = (unsigned int)(v7 + 1024);
      while ( *v7 && (unsigned int)v7 < count )
        *v6++ = *v7++;
      *v6++ = 93;
      if ( ++v5 >= v3 )
        break;
      *v6 = 91;
      v8 = v6 + 1;
      *v8++ = 13;
      *v8 = 10;
      v6 = v8 + 1;
    }
  }
  *v6 = 0;
  if ( !debug_macro_helper_ignore_always_19 )
  {
    HIBYTE(count) = 0;
    vostok::debug::on_error(
      (bool *)&count + 3,
      process_error_true,
      0,
      "assertion_failed",
      "fatal error",
      ".\\strings_detail_tuples.cpp",
      "process",
      (const char *)0x24,
      "buffer overflow: cannot concatenate strings(%d):\r\n%s",
      index,
      &v9);
    if ( vostok::debug::is_debugger_present() || HIBYTE(count) )
      __debugbreak();
  }
}
