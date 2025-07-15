bool __usercall vostok::tasks::thread_pool::current_thread_core_is_oversubscribed@<al>(
        vostok::tasks::thread_pool *this@<ecx>,
        _DWORD *a2@<esi>)
{
  LPVOID Value; // eax
  int v3; // eax

  Value = TlsGetValue(s_thread_affinity_tls_key);
  if ( Value )
    v3 = (int)Value - 1;
  else
    v3 = -1;
  return *(int *)(a2[33] + 4 * v3) > 1 && a2[26] > a2[35];
}
