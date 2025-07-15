_DWORD *__cdecl memalign_hook_ini(unsigned int alignment, char *sz)
{
  __memalign_hook = 0;
  ptmalloc_init();
  return pt3memalign(alignment, sz);
}
