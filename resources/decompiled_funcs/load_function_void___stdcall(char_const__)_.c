void __cdecl load_function_void___stdcall_char_const____(
        void (__stdcall **result)(const char *),
        HINSTANCE__ *const module,
        const char *function_id)
{
  if ( s_bugtrap_usage )
  {
    *result = (void (__stdcall *)(const char *))GetProcAddress(module, function_id);
    if ( !*result )
      s_bugtrap_usage = no_bugtrap;
  }
  else
  {
    *result = 0;
  }
}
