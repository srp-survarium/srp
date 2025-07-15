void __cdecl vostok::tasks::wait_while_all_threads_end_grab_next_task()
{
  vostok::tasks::thread_pool::wait_while_all_threads_end_grab_next_task(s_thread_pool.m_variable);
}
