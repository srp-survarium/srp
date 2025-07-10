void *__cdecl memalign_starter(unsigned int align, unsigned int sz)
{
  return internal_memalign((malloc_state *)&main_arena.buf_[8], align, sz);
}
