LPVOID vostok::threading::free_current_thread_logging_name()
{
  LPVOID result; // eax

  result = TlsGetValue(s_thread_logging_name_tls_key);
  if ( result )
    return (LPVOID)TlsSetValue(s_thread_logging_name_tls_key, 0);
  return result;
}
