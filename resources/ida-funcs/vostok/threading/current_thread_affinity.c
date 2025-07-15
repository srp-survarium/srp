unsigned int __cdecl vostok::threading::current_thread_affinity()
{
  LPVOID Value; // eax

  if ( !s_thread_affinity_tls_key )
    vostok::threading::initialize_thread_affinity_tls_key();
  Value = TlsGetValue(s_thread_affinity_tls_key);
  if ( Value )
    return (unsigned int)Value - 1;
  else
    return -1;
}
