int __cdecl vostok::threading::single_threading_policy::increment<long volatile>(volatile int *value)
{
  return ++*value;
}
