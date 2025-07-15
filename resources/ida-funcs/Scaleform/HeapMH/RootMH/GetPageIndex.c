int __thiscall Scaleform::HeapMH::RootMH::GetPageIndex(
        Scaleform::HeapMH::RootMH *this,
        const Scaleform::HeapMH::PageMH *page)
{
  unsigned int TableCount; // ecx
  int v3; // edx
  unsigned int v4; // eax

  TableCount = this->TableCount;
  v3 = 0;
  if ( !TableCount )
    return -1;
  while ( 1 )
  {
    v4 = page - Scaleform::HeapMH::GlobalPageTableMH.Entries[v3].FirstPage;
    if ( v4 <= Scaleform::HeapMH::GlobalPageTableMH.Entries[v3].SizeMask )
      break;
    if ( ++v3 >= TableCount )
      return -1;
  }
  return v3 | (v4 << 7);
}
