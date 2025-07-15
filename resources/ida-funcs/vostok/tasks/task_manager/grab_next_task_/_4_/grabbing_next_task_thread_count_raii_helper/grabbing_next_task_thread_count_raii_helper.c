void __usercall vostok::tasks::task_manager::grab_next_task_::_4_::grabbing_next_task_thread_count_raii_helper::grabbing_next_task_thread_count_raii_helper(
        vostok::tasks::task_manager::grab_next_task::__l4::grabbing_next_task_thread_count_raii_helper *this@<ecx>,
        vostok::tasks::task_manager::grab_next_task::__l4::grabbing_next_task_thread_count_raii_helper **a2@<eax>)
{
  *a2 = this;
  _InterlockedExchange((volatile __int32 *)this, 1);
}
