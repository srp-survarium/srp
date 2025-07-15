__int64 __usercall vostok::threading::interlocked_exchange@<edx:eax>(volatile __int64 *target@<esi>, __int64 exchange)
{
  signed __int64 v2; // rax
  __int64 v4; // [esp+8h] [ebp-8h]

  do
  {
    HIDWORD(v2) = *((_DWORD *)target + 1);
    LODWORD(v4) = *(_DWORD *)target;
    __SET_PAIR__(HIDWORD(v4), v2, *target);
  }
  while ( _InterlockedCompareExchange64(target, exchange, v2) != v4 );
  return v4;
}
