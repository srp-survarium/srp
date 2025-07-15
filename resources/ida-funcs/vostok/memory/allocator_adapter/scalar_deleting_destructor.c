vostok::memory::stack_allocator *__thiscall vostok::memory::allocator_adapter<vostok::memory::single_size_fixed_allocator<1024,2048,vostok::threading::multi_threading_policy>>::`scalar deleting destructor'(
        vostok::memory::stack_allocator *this,
        char a2)
{
  this->__vftable = (vostok::memory::stack_allocator_vtbl *)&vostok::memory::base_allocator::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
