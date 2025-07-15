void __cdecl load_function_long____stdcall___stdcall_void____EXCEPTION_POINTERS____(
        int (__stdcall *(__stdcall **result)())(_EXCEPTION_POINTERS *),
        HINSTANCE__ *const module,
        const char *function_id)
{
  if ( s_bugtrap_usage )
  {
    *result = (int (__stdcall *(__stdcall *)())(_EXCEPTION_POINTERS *))GetProcAddress(module, function_id);
    if ( !*result )
      s_bugtrap_usage = no_bugtrap;
  }
  else
  {
    *result = 0;
  }
}
