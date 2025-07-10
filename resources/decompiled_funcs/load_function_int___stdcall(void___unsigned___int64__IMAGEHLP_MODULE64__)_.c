void __cdecl load_function_int___stdcall_void___unsigned___int64__IMAGEHLP_MODULE64____(
        int (__stdcall **result)(void *, unsigned __int64, _IMAGEHLP_MODULE64 *),
        HINSTANCE__ *const module,
        const char *module_id,
        const char *function_id)
{
  char string[512]; // [esp+0h] [ebp-208h] BYREF
  void (__cdecl *log_callback)(const char *, bool, bool, const char *); // [esp+204h] [ebp-4h]

  if ( s_use_dbghelp )
  {
    *result = (int (__stdcall *)(void *, unsigned __int64, _IMAGEHLP_MODULE64 *))GetProcAddress(module, function_id);
    if ( !*result )
    {
      log_callback = vostok::debug::get_log_callback();
      if ( log_callback )
      {
        sprintf_s<512>((char (*)[512])string, "can't find function %s in %s", function_id, module_id);
        log_callback("debug", 1, 0, string);
      }
      s_use_dbghelp = 0;
    }
  }
  else
  {
    *result = 0;
  }
}
