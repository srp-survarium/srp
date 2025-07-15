void __thiscall load_library(survarium::game_camera *this)
{
  void (__cdecl *v1)(const char *, bool, bool, const char *); // [esp+4h] [ebp-8h]
  void (__cdecl *log_callback)(const char *, bool, bool, const char *); // [esp+8h] [ebp-4h]

  survarium::weapon_user_dead_state::finalize(this);
  s_use_dbghelp = 1;
  s_dbghelp_handle = LoadLibraryA(s_dbghelp_id);
  if ( s_dbghelp_handle )
  {
    load_function_int___stdcall_unsigned_long_void___void____tagSTACKFRAME64___void___int____stdcall___void___unsigned___int64_void___unsigned_long_unsigned_long____void______stdcall___void___unsigned___int64__unsigned___int64____stdcall___void___unsigned___int64__unsigned___int64____stdcall___void___void____tagADDRESS64_____(
      &s_StackWalk64,
      s_dbghelp_handle,
      s_dbghelp_id,
      "StackWalk64");
    load_function_void_____stdcall_void___unsigned___int64__(
      &s_SymFunctionTableAccess64,
      s_dbghelp_handle,
      s_dbghelp_id,
      "SymFunctionTableAccess64");
    load_function_unsigned___int64___stdcall_void___unsigned___int64__(
      &s_SymGetModuleBase64,
      s_dbghelp_handle,
      s_dbghelp_id,
      "SymGetModuleBase64");
    load_function_unsigned_long___stdcall_char_const___char_const___unsigned_long_unsigned_long__(
      &s_UnDecorateSymbolName,
      s_dbghelp_handle,
      s_dbghelp_id,
      "UnDecorateSymbolName");
    load_function_int___stdcall_void___unsigned___int64_unsigned___int64____IMAGEHLP_SYMBOL64____(
      &s_SymGetSymFromAddr64,
      s_dbghelp_handle,
      s_dbghelp_id,
      "SymGetSymFromAddr64");
    load_function_int___stdcall_void___unsigned___int64_unsigned_long____IMAGEHLP_LINE64____(
      &s_SymGetLineFromAddr64,
      s_dbghelp_handle,
      s_dbghelp_id,
      "SymGetLineFromAddr64");
    load_function_int___stdcall_void___unsigned___int64__IMAGEHLP_MODULE64____(
      &s_SymGetModuleInfo64,
      s_dbghelp_handle,
      s_dbghelp_id,
      "SymGetModuleInfo64");
    load_function_int___stdcall_void___char___int__(&s_SymInitialize, s_dbghelp_handle, s_dbghelp_id, "SymInitialize");
    load_function_int___stdcall_void____(&s_SymCleanup, s_dbghelp_handle, s_dbghelp_id, "SymCleanup");
    load_function_unsigned_long___stdcall_unsigned_long__(
      &s_SymSetOptions,
      s_dbghelp_handle,
      s_dbghelp_id,
      "SymSetOptions");
    load_function_unsigned_long___stdcall_void__(&s_SymGetOptions, s_dbghelp_handle, s_dbghelp_id, "SymGetOptions");
    s_psapi_handle = LoadLibraryA(s_psapi_id);
    if ( s_psapi_handle )
    {
      load_function_unsigned_long___stdcall_void___HINSTANCE_____char___unsigned_long__(
        &s_GetModuleBaseName,
        s_psapi_handle,
        s_psapi_id,
        "GetModuleBaseNameA");
    }
    else
    {
      v1 = vostok::debug::get_log_callback();
      if ( v1 )
        v1("debug", 1, 0, "cannot load psapi library");
    }
  }
  else
  {
    log_callback = vostok::debug::get_log_callback();
    if ( log_callback )
      log_callback("debug", 1, 0, "cannot load dbghelp library");
    s_use_dbghelp = 0;
  }
}
