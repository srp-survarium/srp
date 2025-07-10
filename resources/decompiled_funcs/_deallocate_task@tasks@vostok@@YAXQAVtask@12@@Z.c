void __usercall vostok::tasks::deallocate_task(
        vostok::tasks::task *const task@<eax>,
        vostok::tasks::task_allocator *a2@<ecx>)
{
  vostok::tasks::task_allocator::deallocate(a2, (int)&s_task_manager.m_task_allocator, task);
}
