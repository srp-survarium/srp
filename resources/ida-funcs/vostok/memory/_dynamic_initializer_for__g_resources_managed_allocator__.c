int __thiscall vostok::memory::_dynamic_initializer_for__g_resources_managed_allocator__(
        vostok::memory::managed_allocator *this)
{
  vostok::memory::managed_allocator::managed_allocator(this);
  return atexit(vostok::memory::_dynamic_atexit_destructor_for__g_resources_managed_allocator__);
}
