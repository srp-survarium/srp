__int64 __usercall vostok::threading::interlocked_compare_exchange@<edx:eax>(
        volatile __int64 *target@<esi>,
        __int64 exchange,
        __int64 comperand)
{
  return _InterlockedCompareExchange64(target, exchange, comperand);
}
