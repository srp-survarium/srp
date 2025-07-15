int __cdecl vostok::threading::interlocked_or(volatile int *out_left, unsigned int right)
{
  return _InterlockedOr(out_left, right);
}
