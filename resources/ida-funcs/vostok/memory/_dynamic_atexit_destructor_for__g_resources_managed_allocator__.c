void __thiscall vostok::memory::_dynamic_atexit_destructor_for__g_resources_managed_allocator__(
        vostok::memory::managed_allocator *this)
{
  vostok::memory::managed_allocator::~managed_allocator(
    this,
    (_RTL_CRITICAL_SECTION *)&vostok::memory::g_resources_managed_allocator);
}
