unsigned int __usercall vostok::tasks::thread_pool::calculate_active_task_thread_count@<eax>(
        vostok::tasks::thread_pool *this@<ecx>,
        int a2@<eax>)
{
  return *(_DWORD *)(a2 + 104);
}
