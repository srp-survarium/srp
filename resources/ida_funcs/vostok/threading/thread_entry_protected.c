unsigned int __stdcall vostok::threading::thread_entry_protected(void *argument)
{
  vostok::debug::protected_call(vostok::threading::thread_entry, argument);
  return 0;
}
