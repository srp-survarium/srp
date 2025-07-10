void __usercall vostok::threading::mutex_tasks_unaware::unlock(
        vostok::threading::mutex_tasks_unaware *this@<ecx>,
        _RTL_CRITICAL_SECTION *a2@<eax>)
{
  LeaveCriticalSection(a2);
}
