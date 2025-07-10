void __usercall vostok::tasks::thread_pool::on_task_thread_paused(vostok::tasks::thread_pool *this@<ecx>, int a2@<edi>)
{
  if ( _InterlockedIncrement((volatile signed __int32 *)(a2 + 152)) == (*(_DWORD *)(a2 + 120) - *(_DWORD *)(a2 + 116))
                                                                     / 360 )
    SetEvent(*(HANDLE *)(a2 + 40));
}
