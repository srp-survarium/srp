int __cdecl slwait(volatile int *sl)
{
  do
    _mm_pause();
  while ( _InterlockedExchange(sl, 1) );
  return 0;
}
