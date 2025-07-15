void __usercall vostok::memory::stack_allocator::stack_allocator(
        vostok::memory::stack_allocator *this@<ecx>,
        _DWORD *a2@<eax>)
{
  a2[1] = 0;
  a2[2] = 0;
  a2[3] = 0;
  *a2 = &vostok::memory::stack_allocator::`vftable';
  a2[5] = 0;
}
