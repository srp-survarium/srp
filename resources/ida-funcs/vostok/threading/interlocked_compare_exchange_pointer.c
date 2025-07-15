signed __int32 __cdecl vostok::threading::interlocked_compare_exchange_pointer(
        void *volatile *target,
        void *exchange,
        void *comperand)
{
  return _InterlockedCompareExchange(
           (volatile signed __int32 *)target,
           (signed __int32)exchange,
           (signed __int32)comperand);
}
