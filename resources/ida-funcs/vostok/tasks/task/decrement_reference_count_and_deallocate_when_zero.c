void __usercall vostok::tasks::task::decrement_reference_count_and_deallocate_when_zero(
        vostok::tasks::task *this@<ecx>,
        unsigned int a2@<eax>)
{
  if ( !_InterlockedDecrement((volatile signed __int32 *)(a2 + 92)) )
    vostok::tasks::task_allocator::deallocate(
      (vostok::tasks::task_allocator *)(a2 + 92),
      (vostok::tasks::task *)&s_task_manager.m_task_allocator,
      a2);
}
