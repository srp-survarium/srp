void __cdecl load_function_unsigned___int64___stdcall_void___unsigned___int64__()
{
  void (__cdecl *v0)(const char *, bool, bool, const char *); // edi
  char buffer[512]; // [esp+0h] [ebp-200h] BYREF

  if ( s_use_dbghelp )
  {
    s_SymGetModuleBase64 = (unsigned __int64 (__stdcall *)(void *, unsigned __int64))GetProcAddress(
                                                                                       s_dbghelp_handle,
                                                                                       "SymGetModuleBase64");
    if ( !s_SymGetModuleBase64 )
    {
      v0 = s_log_disable_counter == 0 ? s_log_callback : 0;
      if ( v0 )
      {
        vostok::sprintf<512>((char (*)[512])buffer, "can't find function %s in %s", "SymGetModuleBase64", "dbghelp.dll");
        v0((const char *)&stru_802CB8, 1, 0, buffer);
      }
      s_use_dbghelp = 0;
    }
  }
  else
  {
    s_SymGetModuleBase64 = 0;
  }
}
