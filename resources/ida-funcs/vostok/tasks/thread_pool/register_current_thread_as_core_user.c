void __usercall vostok::tasks::thread_pool::register_current_thread_as_core_user(
        vostok::tasks::thread_pool *this@<ecx>,
        DWORD *a2@<edi>)
{
  unsigned int v2; // ebx
  DWORD v3; // esi
  char *v4; // edx
  char *v5; // ecx

  v2 = vostok::threading::current_thread_affinity();
  _InterlockedExchangeAdd((volatile signed __int32 *)(a2[35] + 4 * v2), 1u);
  EnterCriticalSection((LPCRITICAL_SECTION)&s_mutex_2);
  v3 = a2[32] + 360 * a2[28];
  *(_DWORD *)(v3 + 276) = a2[28];
  *(_DWORD *)(v3 + 284) = v2;
  *(_DWORD *)(v3 + 288) = 1;
  *(_DWORD *)(v3 + 264) = a2;
  *(_DWORD *)(v3 + 268) = v3 + 144;
  v4 = (char *)vostok::threading::current_thread_logging_name();
  v5 = *(char **)(v3 + 296);
  if ( v5 != v4 )
  {
    *(_DWORD *)(v3 + 300) = v5;
    *v5 = 0;
    vostok::buffer_string::operator+=((vostok::buffer_string *)(v3 + 296), v4);
  }
  vostok::threading::tls_set_value(a2[27], (void *)(a2[32] + 360 * a2[28]++));
  LeaveCriticalSection((LPCRITICAL_SECTION)&s_mutex_2);
}
