void __thiscall vostok::threading::mutex_tasks_unaware::mutex_tasks_unaware(
        vostok::threading::mutex_tasks_unaware *this,
        _RTL_CRITICAL_SECTION *lpCriticalSection)
{
  InitializeCriticalSectionAndSpinCount(lpCriticalSection, 0x2710u);
}
