int __thiscall vostok::resources::_dynamic_initializer_for__managed_memory__(
        vostok::threading::mutex_tasks_unaware *this)
{
  vostok::resources::memory_type::memory_type(&vostok::resources::managed_memory, "managed", this);
  return atexit(vostok::resources::_dynamic_atexit_destructor_for__managed_memory__);
}
