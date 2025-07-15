void __cdecl vostok::testing::_dynamic_atexit_destructor_for__s_environment__()
{
  CloseHandle(*(HANDLE *)s_environment.test_watcher_thread_must_exit.m_event.m_event);
}
