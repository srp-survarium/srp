// local variable allocation has failed, the output may be wrong!
void __cdecl vostok::debug::call_stack::get_stack_trace(
        void **stacktrace,
        unsigned int stacktrace_max,
        unsigned int num_to_capture,
        unsigned int *out_hash)
{
  vostok::memory::base_allocator *v4; // ecx
  survarium::game_camera *v5; // ecx
  void *v6; // [esp+0h] [ebp-Ch]
  unsigned __int64 hash_ulong; // [esp+4h] [ebp-8h] OVERLAPPED BYREF
  const char *savedregs; // [esp+Ch] [ebp+0h]

  initialize(v4, v6, hash_ulong, savedregs);
  survarium::weapon_user_dead_state::finalize(v5);
  if ( s_pfnCaptureStackBackTrace )
  {
    HIDWORD(hash_ulong) = s_pfnCaptureStackBackTrace(0, num_to_capture, stacktrace, (unsigned int *)&hash_ulong);
    stacktrace[HIDWORD(hash_ulong)] = 0;
    if ( out_hash )
      *out_hash = hash_ulong;
  }
  else
  {
    *stacktrace = 0;
    if ( out_hash )
      *out_hash = 0;
  }
}
