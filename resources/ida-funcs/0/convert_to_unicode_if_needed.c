wchar_t *__usercall convert_to_unicode_if_needed@<eax>(wchar_t *const output@<esi>, const char *message, int max_count)
{
  if ( s_bugtrap_usage == native_bugtrap )
    return (wchar_t *)message;
  *output = 0;
  MultiByteToWideChar(0, 1u, message, strlen(message) + 1, output, max_count);
  return output;
}
