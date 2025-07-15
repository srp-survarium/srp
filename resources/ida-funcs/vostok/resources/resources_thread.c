volatile int *__thiscall vostok::resources::resources_thread(vostok::resources::resources_manager *this)
{
  vostok::threading::event *v1; // ecx
  vostok::resources::resources_manager *v2; // ecx
  volatile int *result; // eax

  vostok::resources::resources_manager::on_resources_thread_started(this);
  v1 = &s_resources_thread_started;
  _InterlockedExchange((volatile __int32 *)s_resources_thread_started.m_event.m_event, 1);
  for ( ;
        !*(_DWORD *)&s_resources_thread_started.m_event.m_event[4];
        v1 = *(vostok::threading::event **)&s_resources_thread_started.m_event.m_event[4] )
  {
    vostok::threading::event::wait(
      v1,
      (unsigned int)&dword_203D0 + (unsigned int)vostok::resources::g_resources_manager.m_variable);
    vostok::resources::resources_manager::resources_thread_tick(v2);
  }
  vostok::resources::resources_manager::on_resources_thread_ending((vostok::resources::resources_manager *)v1);
  result = &s_resources_thread_finished;
  _InterlockedExchange(&s_resources_thread_finished, 1);
  return result;
}
