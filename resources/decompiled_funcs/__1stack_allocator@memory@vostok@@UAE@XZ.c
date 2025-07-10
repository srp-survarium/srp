void __usercall vostok::memory::stack_allocator::~stack_allocator(
        vostok::memory::stack_allocator *this@<ecx>,
        _DWORD *a2@<eax>)
{
  *a2 = &vostok::memory::base_allocator::`vftable';
}
