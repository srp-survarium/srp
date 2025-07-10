void __thiscall Scaleform::HeapMH::RootMH::RootMH(Scaleform::HeapMH::RootMH *this, Scaleform::SysAlloc *sysAlloc)
{
  unsigned int *p_SizeMask; // eax

  this->pSysAlloc = sysAlloc;
  Scaleform::Lock::Lock(&this->RootLock.mLock, 0);
  this->FreePages.Root.pPrev = (Scaleform::HeapMH::PageMH *)&this->FreePages;
  this->FreePages.Root.pNext = (Scaleform::HeapMH::PageMH *)&this->FreePages;
  this->TableCount = 0;
  this->HeapTree.Root = 0;
  Scaleform::HeapMH::GlobalEmptyPageMH.pHeap = 0;
  Scaleform::HeapMH::GlobalEmptyPageMH.Start = 0;
  p_SizeMask = &Scaleform::HeapMH::GlobalPageTableMH.Entries[0].SizeMask;
  do
  {
    *(p_SizeMask - 1) = (unsigned int)&Scaleform::HeapMH::GlobalEmptyPageMH;
    *p_SizeMask = 0;
    p_SizeMask += 2;
  }
  while ( (int)p_SizeMask < (int)&Scaleform::HeapMH::GlobalEmptyPageMH.4 );
  Scaleform::HeapMH::GlobalRootMH = this;
}
