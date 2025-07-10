__int32 vostok::resources::cooker_thread()
{
  vostok::threading::event *v0; // ecx
  vostok::resources::resources_manager *v1; // ecx

  v0 = &s_cooker_thread_started;
  _InterlockedExchange((volatile __int32 *)s_cooker_thread_started.m_event.m_event, 1);
  for ( ;
        !*(_DWORD *)&s_cooker_thread_started.m_event.m_event[4];
        v0 = *(vostok::threading::event **)&s_cooker_thread_started.m_event.m_event[4] )
  {
    vostok::threading::event::wait(
      v0,
      (unsigned int)&dword_203E0 + (unsigned int)vostok::resources::g_resources_manager.m_variable);
    vostok::resources::resources_manager::cooker_thread_tick(v1);
  }
  vostok::resources::resources_manager::wait_and_dispatch_callbacks(
    (vostok::resources::resources_manager *)v0,
    (bool)vostok::resources::g_resources_manager.m_variable,
    0);
  return _InterlockedExchange(&s_cooker_thread_finished, 1);
}
