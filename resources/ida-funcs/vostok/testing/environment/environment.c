void __thiscall vostok::testing::environment::environment(vostok::testing::environment *this)
{
  s_environment.engine = 0;
  *(_DWORD *)s_environment.test_watcher_thread_must_exit.m_event.m_event = CreateEventA(0, 0, 0, 0);
  s_environment.test_watcher_thread_exited = 0;
  s_environment.test_watcher_thread_started = 0;
  s_environment.num_failed_tests = 0;
  s_environment.current_test_number = 0;
  s_environment.current_test = "undefined";
  s_environment.current_suite = "undefined";
  s_environment.awaited_exception = assert_untyped;
  s_environment.caught_awaited_exception = 0;
  s_environment.is_testing = 0;
  s_environment.exception_index = 0;
  s_environment.num_top_callstack_frames_to_skip = 0;
}
