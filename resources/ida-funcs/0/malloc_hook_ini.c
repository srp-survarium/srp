char *__cdecl malloc_hook_ini(unsigned int sz)
{
  __malloc_hook = 0;
  ptmalloc_init();
  return pt3malloc(sz);
}
