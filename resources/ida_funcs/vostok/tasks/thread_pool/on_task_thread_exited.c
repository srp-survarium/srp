void __usercall vostok::tasks::thread_pool::on_task_thread_exited(vostok::tasks::thread_pool *this@<ecx>, int a2@<esi>)
{
  EnterCriticalSection((LPCRITICAL_SECTION)(a2 + 8));
  if ( _InterlockedIncrement((volatile signed __int32 *)(a2 + 88)) == (*(_DWORD *)(a2 + 120) - *(_DWORD *)(a2 + 116))
                                                                    / 360 )
    SetEvent(*(HANDLE *)(a2 + 96));
  LeaveCriticalSection((LPCRITICAL_SECTION)(a2 + 8));
}
