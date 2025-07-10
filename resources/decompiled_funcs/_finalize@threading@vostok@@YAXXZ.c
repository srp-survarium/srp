void __cdecl vostok::threading::finalize()
{
  if ( TlsGetValue(s_thread_logging_name_tls_key) )
    TlsSetValue(s_thread_logging_name_tls_key, 0);
  if ( s_thread_logging_name_tls_key != -1 )
    TlsFree(s_thread_logging_name_tls_key);
  if ( s_logical_to_physical_core_index )
  {
    pt3free((char *)s_logical_to_physical_core_index);
    s_logical_to_physical_core_index = 0;
  }
}
