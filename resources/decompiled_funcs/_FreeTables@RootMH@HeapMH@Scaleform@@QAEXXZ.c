void __thiscall Scaleform::HeapMH::RootMH::FreeTables(Scaleform::HeapMH::RootMH *this)
{
  Scaleform::HeapMH::PageTableMH *v2; // esi

  v2 = &Scaleform::HeapMH::GlobalPageTableMH;
  do
  {
    if ( v2->Entries[0].FirstPage != &Scaleform::HeapMH::GlobalEmptyPageMH )
      this->pSysAlloc->Free(this->pSysAlloc, v2->Entries[0].FirstPage, 16 * (v2->Entries[0].SizeMask + 1), 4u);
    v2->Entries[0].FirstPage = &Scaleform::HeapMH::GlobalEmptyPageMH;
    v2->Entries[0].SizeMask = 0;
    v2 = (Scaleform::HeapMH::PageTableMH *)((char *)v2 + 8);
  }
  while ( (int)v2 < (int)&Scaleform::HeapMH::GlobalEmptyPageMH );
}
