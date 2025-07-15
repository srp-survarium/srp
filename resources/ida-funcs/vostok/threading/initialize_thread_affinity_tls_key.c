__int32 vostok::threading::initialize_thread_affinity_tls_key()
{
  __int32 result; // eax

  if ( !_InterlockedExchange(&creation_flag, 1) )
    return _InterlockedExchange(&s_thread_affinity_tls_key, TlsAlloc());
  do
    result = s_thread_affinity_tls_key;
  while ( !s_thread_affinity_tls_key );
  return result;
}
