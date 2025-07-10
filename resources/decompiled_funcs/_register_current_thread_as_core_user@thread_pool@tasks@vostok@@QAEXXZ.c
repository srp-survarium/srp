void __usercall vostok::tasks::thread_pool::register_current_thread_as_core_user(
        vostok::tasks::thread_pool *this@<ecx>,
        DWORD *a2@<edi>)
{
  LPVOID Value; // eax
  int v3; // ebx
  int v4; // esi
  const char *v5; // eax
  const char *v6; // edx
  DWORD v7; // [esp-8h] [ebp-10h]

  Value = TlsGetValue(s_thread_affinity_tls_key);
  if ( Value )
    v3 = (int)Value - 1;
  else
    v3 = -1;
  _InterlockedExchangeAdd((volatile signed __int32 *)(a2[33] + 4 * v3), 1u);
  EnterCriticalSection((LPCRITICAL_SECTION)&s_mutex_0);
  v4 = a2[31] + 360 * a2[28];
  v7 = s_thread_logging_name_tls_key;
  *(_DWORD *)(v4 + 276) = a2[28];
  *(_DWORD *)(v4 + 284) = v3;
  *(_DWORD *)(v4 + 288) = 1;
  *(_DWORD *)(v4 + 264) = a2;
  *(_DWORD *)(v4 + 268) = v4 + 144;
  v5 = (const char *)TlsGetValue(v7);
  if ( !v5 )
    v5 = "undefined";
  v6 = *(const char **)(v4 + 296);
  if ( v6 != v5 )
  {
    *(_DWORD *)(v4 + 300) = v6;
    *v6 = 0;
    vostok::buffer_string::operator+=((vostok::buffer_string *)(v4 + 296), v5);
  }
  TlsSetValue(a2[27], (LPVOID)(a2[31] + 360 * a2[28]++));
  LeaveCriticalSection((LPCRITICAL_SECTION)&s_mutex_0);
}
