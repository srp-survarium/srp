int __cdecl vostok::threading::multi_threading_policy::increment<long volatile>(volatile int *value)
{
  return _InterlockedIncrement(value);
}
