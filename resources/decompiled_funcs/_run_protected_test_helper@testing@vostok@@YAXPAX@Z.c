void __cdecl vostok::testing::run_protected_test_helper(void *test)
{
  unsigned int v1; // eax
  void *stacktrace[64]; // [esp+0h] [ebp-100h] BYREF

  vostok::debug::call_stack::get_stack_trace(stacktrace, 0x40u, 0x3Eu, 0);
  v1 = 0;
  s_environment.num_top_callstack_frames_to_skip = 0;
  if ( stacktrace[0] )
  {
    do
      ++v1;
    while ( stacktrace[v1] );
    s_environment.num_top_callstack_frames_to_skip = v1;
  }
  (*(void (__thiscall **)(void *))(*(_DWORD *)test + 4))(test);
}
