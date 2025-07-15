void __usercall _LN17_0(char *const message@<esi>, unsigned int max_message_length, char *format, ...)
{
  unsigned int v3; // edi
  va_list ap; // [esp+10h] [ebp+Ch] BYREF

  va_start(ap, format);
  v3 = strlen(message);
  vsprintf_s(&message[strlen(message)], max_message_length - v3, format, ap);
  if ( (!s_debug_engine || !s_debug_engine->is_testing(s_debug_engine))
    && (s_log_disable_counter == 0 ? (unsigned int)s_log_callback : 0) != 0 )
  {
    ((void (__cdecl *)(const vostok::logging::filter_tree *, int, _DWORD, char *))(s_log_disable_counter == 0
                                                                                 ? (unsigned int)s_log_callback
                                                                                 : 0))(
      &stru_802CB8,
      1,
      0,
      &message[v3]);
  }
  strcat_s(message, max_message_length, "\r\n");
}
