LONG __cdecl vostok::debug::interlocked_decrement(int *value)
{
  return InterlockedDecrement(value);
}
