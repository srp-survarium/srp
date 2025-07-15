virtual_alloc_region *__cdecl mmap(void *ptr)
{
  virtual_alloc_region *result; // eax

  slwait(&g_sl);
  result = virtual_alloc(ptr);
  _mm_pause();
  _InterlockedExchange(&g_sl, 0);
  return result;
}
