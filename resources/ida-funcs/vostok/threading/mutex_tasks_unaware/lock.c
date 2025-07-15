void __usercall vostok::threading::mutex_tasks_unaware::lock(
        vostok::threading::mutex_tasks_unaware *this@<ecx>,
        _RTL_CRITICAL_SECTION *a2@<eax>)
{
  EnterCriticalSection(a2);
}
