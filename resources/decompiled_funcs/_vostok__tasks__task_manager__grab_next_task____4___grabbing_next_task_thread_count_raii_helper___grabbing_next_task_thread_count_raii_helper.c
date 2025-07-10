void __thiscall vostok::tasks::task_manager::grab_next_task_::_4_::grabbing_next_task_thread_count_raii_helper::_grabbing_next_task_thread_count_raii_helper(
        vostok::tasks::task_manager::grab_next_task::__l4::grabbing_next_task_thread_count_raii_helper *this)
{
  _InterlockedExchange(this->m_in_grab_next_task, 0);
}
