int __usercall munmap@<eax>(virtual_alloc_arena *a1@<edi>, void *ptr, unsigned int size)
{
  int result; // eax

  do
    _mm_pause();
  while ( _InterlockedExchange(&g_sl, 1) );
  virtual_free(a1, ptr, size);
  _mm_pause();
  result = 0;
  _InterlockedExchange(&g_sl, 0);
  return result;
}
