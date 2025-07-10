void __usercall vostok::threading::simple_lock::unlock(vostok::threading::simple_lock *this@<ecx>, int a2@<eax>)
{
  if ( (*(_DWORD *)a2)-- == 1 )
    _InterlockedExchange((volatile __int32 *)(a2 + 4), 0);
}
