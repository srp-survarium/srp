void __cdecl vostok::testing::run_protected_test_helper(void *test)
{
  vostok::memory::base_allocator *v1; // ecx
  unsigned int v2; // eax
  void *v3; // [esp+0h] [ebp-108h]
  void *v4[64]; // [esp+4h] [ebp-104h] BYREF
  unsigned int v5; // [esp+104h] [ebp-4h] BYREF

  initialize(v1, v3, *(unsigned __int64 *)v4, (const char *)v4[2]);
  if ( s_pfnCaptureStackBackTrace )
    v4[s_pfnCaptureStackBackTrace(0, 0x3Eu, v4, &v5)] = 0;
  else
    v4[0] = 0;
  v2 = 0;
  s_environment.num_top_callstack_frames_to_skip = 0;
  if ( v4[0] )
  {
    do
      ++v2;
    while ( v4[v2] );
    s_environment.num_top_callstack_frames_to_skip = v2;
  }
  (*(void (__thiscall **)(void *))(*(_DWORD *)test + 4))(test);
}
