int __thiscall vostok::resources::_dynamic_initializer_for__unmanaged_memory__(
        vostok::threading::mutex_tasks_unaware *this)
{
  vostok::resources::memory_type::memory_type(&vostok::resources::unmanaged_memory, "unmanaged", this);
  return atexit(vostok::resources::_dynamic_atexit_destructor_for__unmanaged_memory__);
}
