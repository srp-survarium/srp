void __usercall vostok::memory::stack_allocator::stack_allocator(
        vostok::memory::stack_allocator *this@<ecx>,
        int a2@<eax>)
{
  *(_DWORD *)(a2 + 4) = 0;
  *(_DWORD *)(a2 + 8) = 0;
  *(_DWORD *)(a2 + 12) = 0;
  *(_BYTE *)(a2 + 16) = 0;
  *(_DWORD *)a2 = &vostok::memory::stack_allocator::`vftable';
  *(_DWORD *)(a2 + 20) = 0;
}
