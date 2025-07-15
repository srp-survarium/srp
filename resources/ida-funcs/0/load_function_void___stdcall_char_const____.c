void __usercall load_function_void___stdcall_char_const____(
        void (__stdcall **result)(const char *)@<esi>,
        HINSTANCE__ *const module)
{
  void (__stdcall *ProcAddress)(const char *); // eax

  if ( s_bugtrap_usage )
  {
    ProcAddress = (void (__stdcall *)(const char *))GetProcAddress(s_bugtrap_handle, (LPCSTR)module);
    *result = ProcAddress;
    if ( !ProcAddress )
      s_bugtrap_usage = no_bugtrap;
  }
  else
  {
    *result = 0;
  }
}
