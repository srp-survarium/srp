unsigned __int64 __cdecl vostok::platform::get_local_video_memory_size()
{
  int v0; // edx
  unsigned __int64 v1; // rdi
  unsigned __int64 v2; // rax
  unsigned __int64 v3; // rdi
  unsigned int max_video_memory_size_in_mb; // [esp+8h] [ebp-4h] BYREF

  LODWORD(v1) = get_local_video_memory_size_impl();
  HIDWORD(v1) = v0;
  if ( s_max_video_memory.m_type == type_unset )
  {
    LOBYTE(max_video_memory_size_in_mb) = 0;
    s_max_video_memory.m_type = type_recursive;
    vostok::command_line::iterate_keys<vostok::command_line::key_initializator>();
  }
  if ( s_max_video_memory.m_type != type_recursive
    && vostok::command_line::key::is_set_as_number<unsigned int>(&s_max_video_memory, &max_video_memory_size_in_mb) )
  {
    v2 = vostok::math::max(0x10000000u, (unsigned __int64)max_video_memory_size_in_mb << 20);
    v1 = vostok::math::min(v2, v1);
  }
  v3 = v1 < 0x40000000 ? v1 - 0x40000000 + 0x40000000 : 0x40000000LL;
  __FUnloadDelayLoadedDLL2(&stru_95DC74.m_buffer[272]);
  if ( !v3 )
    return 0x10000000;
  if ( v3 < 0x10000000 )
    vostok::debug::terminate(&stru_95DC74.m_buffer[288]);
  return v3;
}
