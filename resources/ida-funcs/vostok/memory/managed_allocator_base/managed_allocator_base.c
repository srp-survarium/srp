void __usercall vostok::memory::managed_allocator_base::managed_allocator_base(
        vostok::memory::managed_allocator_base *this@<ecx>,
        int a2@<eax>)
{
  *(_DWORD *)(a2 + 16) = 128;
  *(_DWORD *)(a2 + 28) = 0;
  *(_DWORD *)(a2 + 24) = 0;
  *(_DWORD *)(a2 + 32) = 0;
  *(_DWORD *)(a2 + 36) = 0;
  *(_DWORD *)(a2 + 20) = 0;
  *(_DWORD *)a2 = 0;
  *(_BYTE *)(a2 + 8) = 0;
  *(_DWORD *)(a2 + 12) = 0;
  *(_DWORD *)(a2 + 40) = 0;
  *(_DWORD *)(a2 + 4) = 0;
}
