void __cdecl vostok::debug::enable_log_callback()
{
  vostok::debug::interlocked_decrement(&s_log_disable_counter);
}
