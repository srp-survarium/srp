Scaleform::HeapMH::PageMH *__thiscall Scaleform::HeapMH::RootMH::ResolveAddress(
        Scaleform::HeapMH::RootMH *this,
        unsigned int addr)
{
  Scaleform::HeapMH::PageMH *result; // eax

  if ( *(_WORD *)(addr & 0xFFFFF000) != 24512
    || (result = &Scaleform::HeapMH::GlobalPageTableMH.Entries[*(_DWORD *)((addr & 0xFFFFF000) + 4) & 0x7F].FirstPage[Scaleform::HeapMH::GlobalPageTableMH.Entries[*(_DWORD *)((addr & 0xFFFFF000) + 4) & 0x7F].SizeMask & (*(_DWORD *)((addr & 0xFFFFF000) + 4) >> 7)],
        addr - (unsigned int)result->Start >= 0x1000) )
  {
    if ( *(_WORD *)((addr & 0xFFFFF000) + 0xFF0) != 24512 )
      return 0;
    result = &Scaleform::HeapMH::GlobalPageTableMH.Entries[*(_DWORD *)((addr & 0xFFFFF000) + 0xFF4) & 0x7F].FirstPage[Scaleform::HeapMH::GlobalPageTableMH.Entries[*(_DWORD *)((addr & 0xFFFFF000) + 0xFF4) & 0x7F].SizeMask & (*(_DWORD *)((addr & 0xFFFFF000) + 0xFF4) >> 7)];
    if ( addr - (unsigned int)result->Start >= 0x1000 )
      return 0;
  }
  return result;
}
