void output(char *const message, unsigned int max_message_length, const char *format, ...)
{
  vostok::debug::engine *v3; // eax
  unsigned int v4; // [esp+4h] [ebp-30h]
  unsigned int v5; // [esp+14h] [ebp-20h]
  void (__cdecl *log_callback)(const char *, bool, bool, const char *); // [esp+28h] [ebp-Ch]
  va_list va; // [esp+48h] [ebp+14h] BYREF

  va_start(va, format);
  v5 = strlen(message);
  v4 = strlen(message);
  vostok::vsprintf(format, va, &message[v4], max_message_length - v5);
  if ( !vostok::debug::debug_engine()
    || (v3 = vostok::debug::debug_engine(),
        !((unsigned __int8 (__thiscall *)(vostok::debug::engine *, vostok::debug::engine *, unsigned int))v3->is_testing)(
           v3,
           v3,
           v4)) )
  {
    log_callback = vostok::debug::get_log_callback();
    if ( log_callback )
      log_callback("debug", 1, 0, &message[v5]);
  }
  strcat_s(message, max_message_length, "\r\n");
}
