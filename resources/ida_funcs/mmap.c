void *__cdecl mmap(int ptr)
{
  void *result; // eax

  do
    _mm_pause();
  while ( _InterlockedExchange(&g_sl, 1) );
  result = virtual_alloc(0, ptr);
  _mm_pause();
  _InterlockedExchange(&g_sl, 0);
  return result;
}
