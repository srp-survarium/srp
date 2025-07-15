int __usercall munmap@<eax>(virtual_alloc_region *ptr@<esi>, unsigned int size@<edi>)
{
  int result; // eax

  slwait(&g_sl);
  virtual_free(ptr, size);
  _mm_pause();
  result = 0;
  _InterlockedExchange(&g_sl, 0);
  return result;
}
