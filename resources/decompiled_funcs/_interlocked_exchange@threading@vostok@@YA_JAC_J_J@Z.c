unsigned int __cdecl vostok::threading::interlocked_exchange(volatile __int64 *target, __int64 exchange)
{
  volatile __int64 *i; // ecx
  unsigned int v3; // esi
  signed __int64 v4; // rax

  for ( i = target; ; i = target )
  {
    v3 = *(_DWORD *)i;
    v4 = *i;
    if ( _InterlockedCompareExchange64(i, exchange, v4) == __PAIR64__(HIDWORD(v4), v3) )
      break;
  }
  return v3;
}
