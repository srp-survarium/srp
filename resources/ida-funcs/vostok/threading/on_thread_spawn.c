void __cdecl vostok::threading::on_thread_spawn(const vostok::threading::tasks_awareness tasks_awareness)
{
  vostok::command_line::key *v1; // ecx
  vostok::tasks::thread_pool *v3; // ecx

  vostok::math::on_thread_spawn(v1);
  QueryPerformanceFrequency((LARGE_INTEGER *)(*(_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + 8));
  if ( tasks_awareness == tasks_aware )
  {
    if ( s_thread_pool.m_initialized )
      vostok::tasks::thread_pool::register_current_thread_as_core_user(v3, (DWORD *)s_thread_pool.m_variable);
  }
}
