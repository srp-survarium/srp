void __cdecl vostok::debug::protected_call(void (__cdecl *function_to_call)(void *), void *argument)
{
  vostok::debug::set_thread_stack_guarantee();
  function_to_call(argument);
}
