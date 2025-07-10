vostok::tasks::task *__usercall vostok::intrusive_queue<vostok::tasks::task,vostok::tasks::task,8,vostok::threading::mutex>::pop_front@<eax>(
        vostok::intrusive_queue<vostok::tasks::task,vostok::tasks::task,8,vostok::threading::mutex> *this@<ecx>,
        int a2@<edi>)
{
  void **v2; // esi
  __int32 v4; // eax
  __int32 v5; // ecx

  if ( *(_DWORD *)a2 )
    goto pop_front_existing;
LABEL_2:
  while ( 1 )
  {
    vostok::threading::mutex::lock((vostok::threading::mutex *)(a2 + 72));
    if ( !*(_DWORD *)a2 )
      break;
    LeaveCriticalSection((LPCRITICAL_SECTION)(a2 + 72));
pop_front_existing:
    v2 = *(void ***)a2;
    if ( *(_DWORD *)a2 )
    {
      while ( (void **)vostok::threading::interlocked_compare_exchange_pointer((void *volatile *)a2, v2[2], v2) != v2 )
      {
        v2 = *(void ***)a2;
        if ( !*(_DWORD *)a2 )
          goto LABEL_2;
      }
      return (vostok::tasks::task *)v2;
    }
  }
  if ( !*(_DWORD *)(a2 + 64) )
  {
    LeaveCriticalSection((LPCRITICAL_SECTION)(a2 + 72));
    return 0;
  }
  v4 = _InterlockedExchange((volatile __int32 *)(a2 + 64), 0);
  v2 = 0;
  if ( v4 )
  {
    do
    {
      v5 = *(_DWORD *)(v4 + 8);
      *(_DWORD *)(v4 + 8) = v2;
      v2 = (void **)v4;
      v4 = v5;
    }
    while ( v5 );
  }
  *(_DWORD *)a2 = v2[2];
  LeaveCriticalSection((LPCRITICAL_SECTION)(a2 + 72));
  return (vostok::tasks::task *)v2;
}
