void __cdecl vostok::debug::disable_log_callback()
{
  vostok::debug::interlocked_increment(&s_log_disable_counter);
}
