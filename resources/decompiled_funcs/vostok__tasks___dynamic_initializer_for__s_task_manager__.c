int __thiscall vostok::tasks::_dynamic_initializer_for__s_task_manager__(vostok::tasks::task_manager *this)
{
  vostok::tasks::task_manager::task_manager(this);
  return atexit(vostok::tasks::_dynamic_atexit_destructor_for__s_task_manager__);
}
