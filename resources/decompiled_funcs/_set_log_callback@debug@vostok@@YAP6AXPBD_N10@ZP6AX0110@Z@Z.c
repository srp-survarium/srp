void (__cdecl *__cdecl vostok::debug::set_log_callback(
        void (__cdecl *callback)(const char *, bool, bool, const char *)))(const char *, bool, bool, const char *)
{
  void (__cdecl *previous_callback)(const char *, bool, bool, const char *); // [esp+0h] [ebp-4h]

  previous_callback = s_log_callback;
  s_log_callback = callback;
  return previous_callback;
}
