BOOL __usercall vostok::threading::mutex_tasks_unaware::try_lock@<eax>(
        vostok::threading::mutex_tasks_unaware *this@<ecx>,
        _RTL_CRITICAL_SECTION *a2@<eax>)
{
  return TryEnterCriticalSection(a2);
}
