int __thiscall vostok::tasks::_dynamic_initializer_for__s_mutex__(vostok::threading::mutex_tasks_unaware *this)
{
  vostok::threading::mutex_tasks_unaware::mutex_tasks_unaware(this, (_RTL_CRITICAL_SECTION *)&s_mutex_2);
  return atexit(vostok::tasks::_dynamic_atexit_destructor_for__s_mutex__);
}
