_DWORD *Scaleform::HeapPT::PageTable::Init()
{
  _DWORD *result; // eax
  int i; // ecx

  Scaleform::HeapPT::PageTableMem[0] = 0;
  result = &unk_8E88E4;
  for ( i = 4095; i >= 0; --i )
  {
    *result = 0;
    result[1] = 0;
    result += 2;
  }
  Scaleform::HeapPT::GlobalPageTable = (Scaleform::HeapPT::PageTable *)Scaleform::HeapPT::PageTableMem;
  return result;
}
