void __usercall vostok::memory::platform::free_region(void *buffer@<edx>, unsigned __int64 buffer_size)
{
  if ( *(_QWORD *)&s_crt_allocator_creation.m_arena_id )
  {
    *(_QWORD *)&s_crt_allocator_creation.m_arena_id -= buffer_size;
    if ( *(_QWORD *)&s_crt_allocator_creation.m_arena_id )
      return;
    buffer = s_crt_allocator_creation.m_arena_start;
  }
  VirtualFree(buffer, 0, 0x8000u);
}
