void __cdecl load_function_void___stdcall_enum_BUGTRAP_REPORTFORMAT_tag__(
        void (__stdcall **result)(BUGTRAP_REPORTFORMAT_tag),
        HINSTANCE__ *const module,
        const char *function_id)
{
  if ( s_bugtrap_usage )
  {
    *result = (void (__stdcall *)(BUGTRAP_REPORTFORMAT_tag))GetProcAddress(module, function_id);
    if ( !*result )
      s_bugtrap_usage = no_bugtrap;
  }
  else
  {
    *result = 0;
  }
}
