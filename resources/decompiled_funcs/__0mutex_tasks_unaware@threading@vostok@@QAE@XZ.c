void __thiscall vostok::threading::mutex_tasks_unaware::mutex_tasks_unaware(
        vostok::threading::mutex_tasks_unaware *this)
{
  InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)this, 0x2710u);
}
