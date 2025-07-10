void __cdecl load_function_void___cdecl_void__(
        void (__cdecl **result)(),
        HINSTANCE__ *const module,
        const char *function_id)
{
  if ( s_bugtrap_usage )
  {
    *result = (void (__cdecl *)())GetProcAddress(module, function_id);
    if ( !*result )
      s_bugtrap_usage = no_bugtrap;
  }
  else
  {
    *result = 0;
  }
}
