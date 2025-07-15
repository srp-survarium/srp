void __usercall ppmd_allocator::InitSubAllocator(ppmd_allocator *this@<ecx>, _DWORD *a2@<esi>)
{
  int v2; // ecx
  unsigned int v3; // eax
  int v4; // ecx
  int v5; // eax

  memset((int)(a2 + 1), 0, 0x130u);
  v2 = a2[121];
  v3 = a2[120];
  a2[122] = v2;
  v4 = v3 + v2;
  a2[119] = 0;
  a2[125] = v4;
  v5 = v4 - 84 * ((v3 >> 3) / 0xC);
  a2[123] = v5;
  a2[124] = v5;
}
