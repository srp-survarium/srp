void __cdecl vostok::threading::delete_thread_logging_tls_key()
{
  if ( s_thread_logging_name_tls_key != -1 )
    TlsFree(s_thread_logging_name_tls_key);
}
