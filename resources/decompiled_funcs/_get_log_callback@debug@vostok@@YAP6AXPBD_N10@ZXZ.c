void (__cdecl *__cdecl vostok::debug::get_log_callback())(const char *, bool, bool, const char *)
{
  return s_log_disable_counter == 0 ? s_log_callback : 0;
}
