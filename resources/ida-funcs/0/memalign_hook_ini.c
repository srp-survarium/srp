char *__cdecl memalign_hook_ini(unsigned int alignment, unsigned int sz)
{
  __memalign_hook = 0;
  ptmalloc_init();
  return pt3memalign(alignment, sz);
}
