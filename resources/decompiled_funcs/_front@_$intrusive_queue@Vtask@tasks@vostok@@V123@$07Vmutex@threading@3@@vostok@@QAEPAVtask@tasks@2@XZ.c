vostok::tasks::task *__usercall vostok::intrusive_queue<vostok::tasks::task,vostok::tasks::task,8,vostok::threading::mutex>::front@<eax>(
        vostok::intrusive_queue<vostok::tasks::task,vostok::tasks::task,8,vostok::threading::mutex> *this@<ecx>,
        int a2@<edi>)
{
  vostok::tasks::task *result; // eax
  __int32 v3; // eax
  __int32 v4; // esi
  __int32 v5; // ecx

  if ( *(_DWORD *)a2 )
    goto pop_front_existing_0;
  while ( 1 )
  {
    vostok::threading::mutex::lock((vostok::threading::mutex *)(a2 + 72));
    if ( !*(_DWORD *)a2 )
      break;
    LeaveCriticalSection((LPCRITICAL_SECTION)(a2 + 72));
pop_front_existing_0:
    result = *(vostok::tasks::task **)a2;
    if ( *(_DWORD *)a2 )
      return result;
  }
  if ( *(_DWORD *)(a2 + 64) )
  {
    v3 = _InterlockedExchange((volatile __int32 *)(a2 + 64), 0);
    v4 = 0;
    if ( v3 )
    {
      do
      {
        v5 = *(_DWORD *)(v3 + 8);
        *(_DWORD *)(v3 + 8) = v4;
        v4 = v3;
        v3 = v5;
      }
      while ( v5 );
    }
    *(_DWORD *)a2 = v4;
    LeaveCriticalSection((LPCRITICAL_SECTION)(a2 + 72));
    return (vostok::tasks::task *)v4;
  }
  else
  {
    LeaveCriticalSection((LPCRITICAL_SECTION)(a2 + 72));
    return 0;
  }
}
