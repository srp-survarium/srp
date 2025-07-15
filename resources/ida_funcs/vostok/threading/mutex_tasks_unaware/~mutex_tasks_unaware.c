void __thiscall vostok::threading::mutex_tasks_unaware::~mutex_tasks_unaware(
        vostok::threading::mutex_tasks_unaware *this)
{
  DeleteCriticalSection((LPCRITICAL_SECTION)this);
}
