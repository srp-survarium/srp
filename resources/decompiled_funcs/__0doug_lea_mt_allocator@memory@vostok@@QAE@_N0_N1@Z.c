void __usercall vostok::memory::doug_lea_mt_allocator::doug_lea_mt_allocator(
        vostok::memory::doug_lea_mt_allocator *this@<ecx>,
        int a2@<esi>)
{
  *(_DWORD *)(a2 + 4) = 0;
  *(_DWORD *)(a2 + 8) = 0;
  *(_DWORD *)(a2 + 12) = 0;
  *(_DWORD *)a2 = &vostok::memory::doug_lea_allocator::`vftable';
  *(_DWORD *)(a2 + 20) = 0;
  *(_DWORD *)(a2 + 24) = "invalid thread id";
  *(_DWORD *)(a2 + 28) = 0;
  *(_BYTE *)(a2 + 32) = 0;
  *(_DWORD *)(a2 + 36) = GetCurrentThreadId();
  *(_BYTE *)(a2 + 40) = 1;
  *(_BYTE *)(a2 + 41) = 0;
  *(_BYTE *)(a2 + 42) = 0;
  *(_BYTE *)(a2 + 43) = 0;
  *(_DWORD *)a2 = &vostok::memory::doug_lea_mt_allocator::`vftable';
  InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)(a2 + 56), 0x2710u);
  InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)(a2 + 80), 0x2710u);
  *(_BYTE *)(a2 + 104) = 0;
}
