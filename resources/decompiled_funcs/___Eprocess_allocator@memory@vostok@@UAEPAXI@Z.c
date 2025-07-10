vostok::memory::doug_lea_allocator *__thiscall vostok::memory::process_allocator::`vector deleting destructor'(
        vostok::memory::doug_lea_allocator *this,
        char a2)
{
  this->__vftable = (vostok::memory::doug_lea_allocator_vtbl *)&vostok::memory::base_allocator::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
