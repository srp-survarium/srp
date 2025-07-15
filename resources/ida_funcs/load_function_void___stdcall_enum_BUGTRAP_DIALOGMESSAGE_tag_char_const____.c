void __cdecl load_function_void___stdcall_enum_BUGTRAP_DIALOGMESSAGE_tag_char_const____(
        void (__stdcall **result)(BUGTRAP_DIALOGMESSAGE_tag, const char *),
        HINSTANCE__ *const module,
        const char *function_id)
{
  if ( s_bugtrap_usage )
  {
    *result = (void (__stdcall *)(BUGTRAP_DIALOGMESSAGE_tag, const char *))GetProcAddress(module, function_id);
    if ( !*result )
      s_bugtrap_usage = no_bugtrap;
  }
  else
  {
    *result = 0;
  }
}
