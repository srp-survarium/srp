int __cdecl interlockedexchange(volatile int *data, int value)
{
  _mm_pause();
  return _InterlockedExchange(data, value);
}
