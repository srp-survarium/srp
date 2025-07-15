void *__cdecl malloc_starter(unsigned int sz)
{
  return vostok_mspace_malloc(&main_arena.buf_[8], sz);
}
