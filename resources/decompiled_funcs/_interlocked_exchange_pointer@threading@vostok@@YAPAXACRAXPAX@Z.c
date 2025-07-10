int __usercall vostok::threading::interlocked_exchange_pointer@<eax>(volatile int *target@<ecx>, int value@<eax>)
{
  return _InterlockedExchange(target, value);
}
