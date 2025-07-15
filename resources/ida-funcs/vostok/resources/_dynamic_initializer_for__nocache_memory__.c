int __thiscall vostok::resources::_dynamic_initializer_for__nocache_memory__(
        vostok::threading::mutex_tasks_unaware *this)
{
  vostok::resources::memory_type::memory_type(&vostok::resources::nocache_memory, "memory_type_non_cacheable", this);
  return atexit(vostok::resources::_dynamic_atexit_destructor_for__nocache_memory__);
}
