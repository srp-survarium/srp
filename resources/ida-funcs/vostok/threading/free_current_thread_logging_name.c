void __cdecl vostok::threading::free_current_thread_logging_name()
{
  if ( TlsGetValue(s_thread_logging_name_tls_key) )
    TlsSetValue(s_thread_logging_name_tls_key, 0);
}
