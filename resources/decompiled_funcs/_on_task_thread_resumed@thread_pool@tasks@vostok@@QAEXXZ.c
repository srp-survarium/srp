void __usercall vostok::tasks::thread_pool::on_task_thread_resumed(
        vostok::tasks::thread_pool *this@<ecx>,
        int a2@<eax>)
{
  if ( !_InterlockedExchangeAdd((volatile signed __int32 *)(a2 + 152), 0xFFFFFFFF) )
    SetEvent(*(HANDLE *)(a2 + 48));
}
