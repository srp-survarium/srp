vostok::memory::managed_allocator *__thiscall vostok::memory::managed_allocator::`vector deleting destructor'(
        vostok::memory::managed_allocator *this,
        char a2)
{
  vostok::memory::managed_allocator::~managed_allocator(this, (_RTL_CRITICAL_SECTION *)this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
