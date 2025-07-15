void __cdecl vostok::threading::preinitialize()
{
  s_thread_logging_name_tls_key = TlsAlloc();
}
