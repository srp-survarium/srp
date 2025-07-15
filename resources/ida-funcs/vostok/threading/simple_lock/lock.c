void __thiscall vostok::threading::simple_lock::lock(vostok::threading::simple_lock *this, int a2)
{
  if ( *(_DWORD *)(a2 + 4) == GetCurrentThreadId() )
  {
    ++*(_DWORD *)a2;
  }
  else
  {
    while ( _InterlockedCompareExchange((volatile signed __int32 *)(a2 + 4), GetCurrentThreadId(), 0) )
      ;
    *(_DWORD *)a2 = 1;
  }
}
