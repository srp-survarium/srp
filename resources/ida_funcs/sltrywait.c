BOOL __cdecl sltrywait(volatile int *sl)
{
  _mm_pause();
  return _InterlockedExchange(sl, 1) != 0;
}
