_DWORD *__cdecl realloc_hook_ini(char *ptr, char *sz)
{
  __malloc_hook = 0;
  __realloc_hook = 0;
  ptmalloc_init();
  return pt3realloc(ptr, sz);
}
