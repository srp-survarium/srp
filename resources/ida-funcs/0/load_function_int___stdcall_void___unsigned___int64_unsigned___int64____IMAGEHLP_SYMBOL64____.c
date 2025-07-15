void __cdecl load_function_int___stdcall_void___unsigned___int64_unsigned___int64____IMAGEHLP_SYMBOL64____()
{
  void (__cdecl *v0)(const char *, bool, bool, const char *); // edi
  char buffer[512]; // [esp+0h] [ebp-200h] BYREF

  if ( s_use_dbghelp )
  {
    s_SymGetSymFromAddr64 = (int (__stdcall *)(void *, unsigned __int64, unsigned __int64 *, _IMAGEHLP_SYMBOL64 *))GetProcAddress(s_dbghelp_handle, "SymGetSymFromAddr64");
    if ( !s_SymGetSymFromAddr64 )
    {
      v0 = s_log_disable_counter == 0 ? s_log_callback : 0;
      if ( v0 )
      {
        vostok::sprintf<512>(
          (char (*)[512])buffer,
          "can't find function %s in %s",
          "SymGetSymFromAddr64",
          "dbghelp.dll");
        v0((const char *)&stru_802CB8, 1, 0, buffer);
      }
      s_use_dbghelp = 0;
    }
  }
  else
  {
    s_SymGetSymFromAddr64 = 0;
  }
}
