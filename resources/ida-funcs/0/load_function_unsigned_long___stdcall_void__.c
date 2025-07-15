void __cdecl load_function_unsigned_long___stdcall_void__()
{
  void (__cdecl *v0)(const char *, bool, bool, const char *); // edi
  char buffer[512]; // [esp+0h] [ebp-200h] BYREF

  if ( s_use_dbghelp )
  {
    s_SymGetOptions = (unsigned int (__stdcall *)())GetProcAddress(s_dbghelp_handle, "SymGetOptions");
    if ( !s_SymGetOptions )
    {
      v0 = s_log_disable_counter == 0 ? s_log_callback : 0;
      if ( v0 )
      {
        vostok::sprintf<512>((char (*)[512])buffer, "can't find function %s in %s", "SymGetOptions", "dbghelp.dll");
        v0((const char *)&stru_802CB8, 1, 0, buffer);
      }
      s_use_dbghelp = 0;
    }
  }
  else
  {
    s_SymGetOptions = 0;
  }
}
