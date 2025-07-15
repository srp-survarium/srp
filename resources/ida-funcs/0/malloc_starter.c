malloc_chunk **__cdecl malloc_starter(unsigned int sz)
{
  return vostok_mspace_malloc((malloc_state *)&main_arena.buf_[8], sz);
}
