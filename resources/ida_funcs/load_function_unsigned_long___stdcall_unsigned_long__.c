void __cdecl load_function_unsigned_long___stdcall_unsigned_long__(
        unsigned int (__stdcall **result)(unsigned int),
        HINSTANCE__ *const module,
        const char *module_id,
        const char *function_id)
{
  char string[512]; // [esp+0h] [ebp-208h] BYREF
  void (__cdecl *log_callback)(const char *, bool, bool, const char *); // [esp+204h] [ebp-4h]

  if ( s_use_dbghelp )
  {
    *result = (unsigned int (__stdcall *)(unsigned int))GetProcAddress(module, function_id);
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
