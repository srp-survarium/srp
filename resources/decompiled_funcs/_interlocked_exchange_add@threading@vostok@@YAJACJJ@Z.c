int __cdecl vostok::threading::interlocked_exchange_add(volatile int *value, unsigned int increment)
{
  return _InterlockedExchangeAdd(value, increment);
}
