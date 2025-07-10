LONG __cdecl vostok::debug::interlocked_increment(int *value)
{
  return InterlockedIncrement(value);
}
