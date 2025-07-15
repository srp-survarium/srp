// attributes: thunk
void *__cdecl _realloc_crt(void *ptr, unsigned int size)
{
  return realloc(ptr, size);
}
