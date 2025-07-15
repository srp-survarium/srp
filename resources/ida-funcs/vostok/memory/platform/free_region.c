void __cdecl vostok::memory::platform::free_region(unsigned __int64 buffer_size)
{
  void *v1; // ecx

  if ( s_single_block_arena_size )
  {
    s_single_block_arena_size -= buffer_size;
    if ( s_single_block_arena_size )
      return;
    v1 = s_single_block_arena;
  }
  VirtualFree(v1, 0, 0x8000u);
}
