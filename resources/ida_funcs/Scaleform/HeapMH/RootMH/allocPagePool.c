char __thiscall Scaleform::HeapMH::RootMH::allocPagePool(Scaleform::HeapMH::RootMH *this)
{
  unsigned int TableCount; // ecx
  int v4; // esi
  Scaleform::HeapMH::PageMH *v5; // eax
  Scaleform::List<Scaleform::HeapMH::PageMH,Scaleform::HeapMH::PageMH> *p_FreePages; // ecx

  TableCount = this->TableCount;
  if ( TableCount < 0x80 )
  {
    v4 = 128 << (TableCount >> 4);
    v5 = (Scaleform::HeapMH::PageMH *)this->pSysAlloc->Alloc(this->pSysAlloc, 16 * v4, 4);
    if ( v5 )
    {
      Scaleform::HeapMH::GlobalPageTableMH.Entries[this->TableCount].FirstPage = v5;
      Scaleform::HeapMH::GlobalPageTableMH.Entries[this->TableCount].SizeMask = v4 - 1;
      if ( v4 )
      {
        p_FreePages = &this->FreePages;
        do
        {
          v5->pHeap = 0;
          v5->Start = 0;
          v5->pPrev = p_FreePages->Root.pPrev;
          v5->pNext = (Scaleform::HeapMH::PageMH *)p_FreePages;
          p_FreePages->Root.pPrev->pNext = v5;
          p_FreePages->Root.pPrev = v5++;
          --v4;
        }
        while ( v4 );
      }
      ++this->TableCount;
      return 1;
    }
    else
    {
      return 0;
    }
  }
  else
  {
    MEMORY[4] = 0;
    return 0;
  }
}
