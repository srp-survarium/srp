void __usercall ppmd_allocator::InitSubAllocator(ppmd_allocator *this@<ecx>, int a2@<esi>)
{
  int v2; // eax
  unsigned int v3; // ecx
  unsigned int v4; // edx

  memset((unsigned __int8 *)(a2 + 4), 0, 0x130u);
  v2 = *(_DWORD *)(a2 + 484);
  v3 = *(_DWORD *)(a2 + 480);
  *(_DWORD *)(a2 + 488) = v2;
  v4 = 84 * ((v3 >> 3) / 0xC);
  *(_DWORD *)(a2 + 500) = v3 + v2;
  *(_DWORD *)(a2 + 492) = v3 + v2 - v4;
  *(_DWORD *)(a2 + 496) = v3 + v2 - v4;
  *(_DWORD *)(a2 + 476) = 0;
}
