int __cdecl vostok::threading::interlocked_and(volatile int *out_left, unsigned int right)
{
  return _InterlockedAnd(out_left, right);
}
