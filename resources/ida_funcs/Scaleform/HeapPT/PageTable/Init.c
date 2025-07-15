void __cdecl Scaleform::HeapPT::PageTable::Init()
{
  _DWORD *v0; // eax
  int i; // ecx

  Scaleform::HeapPT::PageTableMem[0] = 0;
  v0 = &unk_AA4144;
  for ( i = 4095; i >= 0; --i )
  {
    *v0 = 0;
    v0[1] = 0;
    v0 += 2;
  }
  Scaleform::HeapPT::GlobalPageTable = (Scaleform::HeapPT::PageTable *)Scaleform::HeapPT::PageTableMem;
}
