LONG __cdecl vostok::debug::interlocked_compare_exchange(int *target, LONG value, LONG comparand)
{
  return InterlockedCompareExchange(target, value, comparand);
}
