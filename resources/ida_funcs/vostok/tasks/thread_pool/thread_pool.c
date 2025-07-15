void __userpurge vostok::tasks::thread_pool::thread_pool(
        vostok::tasks::thread_pool *this@<ecx>,
        int a2@<edi>,
        unsigned int max_task_threads,
        unsigned int max_user_threads,
        unsigned int min_permanent_working_threads,
        vostok::tasks::execute_while_wait_for_children_enum execute_while_wait_for_children,
        vostok::tasks::do_logging_bool do_logging)
{
  _DWORD *v7; // eax
  _DWORD *v8; // eax
  _DWORD *v9; // eax
  vostok::buffer_vector<vostok::tasks::thread_tls> *v10; // ecx
  vostok::buffer_vector<vostok::tasks::thread_tls> *v11; // ecx
  unsigned int v12; // ecx
  unsigned int i; // esi
  _DWORD *v14; // eax
  vostok::threading *v15; // [esp+0h] [ebp-14h]
  unsigned int spin_count; // [esp+10h] [ebp-4h] BYREF

  *(_DWORD *)a2 = 1;
  InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)(a2 + 8), 0x2710u);
  *(_DWORD *)(a2 + 32) = CreateEventA(0, 0, 0, 0);
  *(_DWORD *)(a2 + 40) = CreateEventA(0, 0, 0, 0);
  *(_DWORD *)(a2 + 48) = CreateEventA(0, 0, 0, 0);
  *(_DWORD *)(a2 + 56) = CreateEventA(0, 0, 0, 0);
  vostok::timing::timer::timer((vostok::timing::timer *)(a2 + 64));
  *(_DWORD *)(a2 + 88) = 0;
  *(_DWORD *)(a2 + 96) = CreateEventA(0, 0, 0, 0);
  *(_DWORD *)(a2 + 104) = 0;
  *(_DWORD *)(a2 + 108) = 0;
  *(_DWORD *)(a2 + 112) = 0;
  v7 = pt3malloc((char *)(360 * max_task_threads));
  *(_DWORD *)(a2 + 116) = v7;
  *(_DWORD *)(a2 + 120) = v7;
  v8 = pt3malloc((char *)0x5A00);
  *(_DWORD *)(a2 + 124) = v8;
  *(_DWORD *)(a2 + 128) = v8;
  if ( !s_logical_core_count )
  {
    vostok::threading::initialize_core_count(v15);
    if ( !s_logical_core_count )
      vostok::threading::initialize_core_count(v15);
  }
  v9 = pt3malloc((char *)(4 * s_logical_core_count));
  *(_DWORD *)(a2 + 132) = v9;
  *(_DWORD *)(a2 + 136) = v9;
  *(_DWORD *)(a2 + 140) = max_user_threads;
  *(_DWORD *)(a2 + 144) = 0;
  *(_DWORD *)(a2 + 148) = 0;
  *(_DWORD *)(a2 + 152) = 0;
  *(_BYTE *)(a2 + 156) = 0;
  *(_DWORD *)(a2 + 160) = 0;
  spin_count = 0;
  if ( vostok::command_line::key::is_set_as_number<unsigned int>(&s_spin_count_key, &spin_count) )
  {
    v10 = &s_spin_count;
    _InterlockedExchange((volatile __int32 *)&s_spin_count, spin_count);
  }
  vostok::buffer_vector<vostok::tasks::thread_tls>::resize(v10, (int *)(a2 + 116), max_task_threads);
  vostok::buffer_vector<vostok::tasks::thread_tls>::resize(v11, (int *)(a2 + 124), 0x40u);
  *(_DWORD *)(a2 + 108) = TlsAlloc();
  ResetEvent(*(HANDLE *)(a2 + 32));
  v12 = s_logical_core_count;
  for ( i = 0; ; ++i )
  {
    if ( !v12 )
    {
      vostok::threading::initialize_core_count(v15);
      v12 = s_logical_core_count;
    }
    if ( i >= v12 )
      break;
    v14 = *(_DWORD **)(a2 + 136);
    if ( v14 )
      *v14 = 0;
    *(_DWORD *)(a2 + 136) += 4;
  }
  *(_DWORD *)(a2 + 92) = 0;
}
