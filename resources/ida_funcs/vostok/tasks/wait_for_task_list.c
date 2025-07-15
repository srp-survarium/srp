void __usercall vostok::tasks::wait_for_task_list(
        vostok::tasks::task *task_list@<eax>,
        vostok::tasks::thread_pool *a2@<ecx>)
{
  vostok::tasks::thread_pool::wait_for_task_list(a2, task_list);
}
