int __fastcall vostok::threading::interlocked_compare_exchange(int exchange, volatile int *target, int comperand)
{
  return _InterlockedCompareExchange(target, exchange, comperand);
}
