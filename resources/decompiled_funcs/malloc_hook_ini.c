_DWORD *__cdecl malloc_hook_ini(char *sz)
{
  __malloc_hook = 0;
  ptmalloc_init();
  return pt3malloc(sz);
}
