void __usercall vostok::tasks::thread_tls::thread_proc_impl(vostok::tasks::thread_tls *this@<ecx>, int a2@<edi>)
{
  int v2; // esi
  signed __int32 v3; // ecx
  int v4; // ecx
  int v5; // eax
  vostok::tasks::task *v6; // ecx
  vostok::tasks::thread_pool *v7; // eax
  vostok::tasks::task_manager *v8; // ecx
  vostok::timing::timer *v9; // ecx
  unsigned __int64 elapsed_ticks; // rax
  bool v11; // [esp+Bh] [ebp-5h]
  vostok::tasks::task *task; // [esp+Ch] [ebp-4h]

  v2 = *(_DWORD *)(a2 + 264);
  v11 = 1;
  vostok::threading::tls_set_value(*(_DWORD *)(v2 + 108), (void *)a2);
  v3 = _InterlockedIncrement((volatile signed __int32 *)(v2 + 92));
  if ( v3 == (*(_DWORD *)(v2 + 120) - *(_DWORD *)(v2 + 116)) / 360 )
    SetEvent(*(HANDLE *)(v2 + 56));
  while ( 1 )
  {
    while ( 1 )
    {
      if ( v11 )
      {
        WaitForSingleObject(*(HANDLE *)(a2 + 64), 0xFFFFFFFF);
        vostok::threading::set_current_thread_affinity(*(char **)(a2 + 284));
        v11 = 0;
      }
      if ( *(_DWORD *)(*(_DWORD *)(a2 + 264) + 160) )
      {
        v4 = *(_DWORD *)(a2 + 264);
        if ( _InterlockedIncrement((volatile signed __int32 *)(v4 + 164)) == (*(_DWORD *)(v4 + 120)
                                                                            - *(_DWORD *)(v4 + 116))
                                                                           / 360 )
          SetEvent(*(HANDLE *)(v4 + 40));
        WaitForSingleObject(*(HANDLE *)(a2 + 248), 0xFFFFFFFF);
        v5 = *(_DWORD *)(a2 + 264);
        v3 = v5 + 164;
        if ( !_InterlockedExchangeAdd((volatile signed __int32 *)(v5 + 164), 0xFFFFFFFF) )
          SetEvent(*(HANDLE *)(v5 + 48));
      }
      task = vostok::tasks::task_manager::grab_next_task((vostok::tasks::task_manager *)v3);
      if ( !task )
        break;
LABEL_14:
      vostok::tasks::task::execute(v6, task);
      elapsed_ticks = vostok::timing::timer::get_elapsed_ticks(v9, *(_DWORD *)(a2 + 264) + 64);
      vostok::threading::interlocked_exchange((volatile __int64 *)(a2 + 344), elapsed_ticks);
      v3 = _InterlockedExchangeAdd((volatile signed __int32 *)(a2 + 352), 1u);
      if ( !*(_DWORD *)(*(_DWORD *)(a2 + 264) + 156) )
        v11 = vostok::tasks::thread_pool::deactivate_if_oversubscribed(
                *(vostok::tasks::thread_pool **)(a2 + 264),
                (vostok::tasks::thread_tls *)a2);
    }
    v7 = *(vostok::tasks::thread_pool **)(a2 + 264);
    if ( v7->m_destroying )
      break;
    v11 = 1;
    vostok::tasks::thread_pool::deactivate_task_thread(v7, (vostok::tasks::thread_tls *)a2);
    task = vostok::tasks::task_manager::grab_next_task(v8);
    if ( task )
    {
      v11 = 0;
      vostok::tasks::thread_pool::try_activate_task_thread(
        *(vostok::tasks::thread_pool **)(a2 + 264),
        (vostok::tasks::thread_tls *)a2,
        *(_DWORD *)(a2 + 284));
      WaitForSingleObject(*(HANDLE *)(a2 + 64), 0xFFFFFFFF);
      vostok::threading::set_current_thread_affinity(*(char **)(a2 + 284));
      goto LABEL_14;
    }
  }
  vostok::tasks::thread_pool::deactivate_task_thread(v7, (vostok::tasks::thread_tls *)a2);
}
