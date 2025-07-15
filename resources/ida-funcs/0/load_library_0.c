void load_library_0()
{
  s_use_dbghelp = 1;
  s_dbghelp_handle = LoadLibraryA("dbghelp.dll");
  if ( s_dbghelp_handle )
  {
    load_function_int___stdcall_unsigned_long_void___void____tagSTACKFRAME64___void___int____stdcall___void___unsigned___int64_void___unsigned_long_unsigned_long____void______stdcall___void___unsigned___int64__unsigned___int64____stdcall___void___unsigned___int64__unsigned___int64____stdcall___void___void____tagADDRESS64_____();
    load_function_void_____stdcall_void___unsigned___int64__();
    load_function_unsigned___int64___stdcall_void___unsigned___int64__();
    load_function_unsigned_long___stdcall_char_const___char_const___unsigned_long_unsigned_long__();
    load_function_int___stdcall_void___unsigned___int64_unsigned___int64____IMAGEHLP_SYMBOL64____();
    load_function_int___stdcall_void___unsigned___int64_unsigned_long____IMAGEHLP_LINE64____();
    load_function_int___stdcall_void___unsigned___int64__IMAGEHLP_MODULE64____();
    load_function_int___stdcall_void___char___int__();
    load_function_int___stdcall_void____();
    load_function_unsigned_long___stdcall_unsigned_long__();
    load_function_unsigned_long___stdcall_void__();
    s_psapi_handle = LoadLibraryA("psapi.dll");
    if ( s_psapi_handle )
    {
      load_function_unsigned_long___stdcall_void___HINSTANCE_____char___unsigned_long__();
    }
    else if ( (s_log_disable_counter == 0 ? (unsigned int)s_log_callback : 0) != 0 )
    {
      ((void (__cdecl *)(const vostok::logging::filter_tree *, int, _DWORD, const char *))(s_log_disable_counter == 0
                                                                                         ? (unsigned int)s_log_callback
                                                                                         : 0))(
        &stru_802CB8,
        1,
        0,
        "cannot load psapi library");
    }
  }
  else
  {
    if ( (s_log_disable_counter == 0 ? (unsigned int)s_log_callback : 0) != 0 )
      ((void (__cdecl *)(const vostok::logging::filter_tree *, int, _DWORD, const char *))(s_log_disable_counter == 0
                                                                                         ? (unsigned int)s_log_callback
                                                                                         : 0))(
        &stru_802CB8,
        1,
        0,
        "cannot load dbghelp library");
    s_use_dbghelp = 0;
  }
}
