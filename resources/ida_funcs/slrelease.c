int __cdecl slrelease(volatile int *sl)
{
  int result; // eax

  _mm_pause();
  result = 0;
  _InterlockedExchange(sl, 0);
  return result;
}
