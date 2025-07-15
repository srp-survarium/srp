void __cdecl load_function_void_____stdcall_void___unsigned___int64__()
{
  void (__cdecl *v0)(const char *, bool, bool, const char *); // edi
  char buffer[512]; // [esp+0h] [ebp-200h] BYREF

  if ( s_use_dbghelp )
  {
    s_SymFunctionTableAccess64 = (void *(__stdcall *)(void *, unsigned __int64))GetProcAddress(
                                                                                  s_dbghelp_handle,
                                                                                  "SymFunctionTableAccess64");
    if ( !s_SymFunctionTableAccess64 )
    {
      v0 = s_log_disable_counter == 0 ? s_log_callback : 0;
      if ( v0 )
      {
        vostok::sprintf<512>(
          (char (*)[512])buffer,
          "can't find function %s in %s",
          "SymFunctionTableAccess64",
          "dbghelp.dll");
        v0((const char *)&stru_802CB8, 1, 0, buffer);
      }
      s_use_dbghelp = 0;
    }
  }
  else
  {
    s_SymFunctionTableAccess64 = 0;
  }
}
