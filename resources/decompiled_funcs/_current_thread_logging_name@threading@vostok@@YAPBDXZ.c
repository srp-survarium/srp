const char *__cdecl vostok::threading::current_thread_logging_name()
{
  const char *result; // eax

  result = (const char *)TlsGetValue(s_thread_logging_name_tls_key);
  if ( !result )
    return "undefined";
  return result;
}
