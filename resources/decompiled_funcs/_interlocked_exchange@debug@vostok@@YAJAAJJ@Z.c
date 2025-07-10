LONG __cdecl vostok::debug::interlocked_exchange(int *target, LONG value)
{
  return InterlockedExchange(target, value);
}
