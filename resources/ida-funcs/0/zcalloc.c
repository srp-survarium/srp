void *__cdecl zcalloc(void *opaque, unsigned int items, unsigned int size)
{
  return malloc(size * items);
}
