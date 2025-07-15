BOOL __usercall vostok::threading::mutex::try_lock@<eax>(
        vostok::threading::mutex *this@<ecx>,
        _RTL_CRITICAL_SECTION *a2@<eax>)
{
  return TryEnterCriticalSection(a2);
}
