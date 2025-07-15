Scaleform::HeapMH::PageMH *__thiscall Scaleform::HeapMH::AllocEngineMH::allocPageLocked(
        Scaleform::HeapMH::AllocEngineMH *this,
        bool *limHandlerOK)
{
  unsigned int Limit; // eax
  Scaleform::LockSafe *p_RootLock; // edi
  const Scaleform::HeapMH::PageMH *v6; // eax
  Scaleform::HeapMH::PageMH *v7; // edi
  unsigned int PageIndex; // eax

  Limit = this->Limit;
  if ( Limit && this->Footprint + 4096 > Limit && this->pLimHandler )
  {
    p_RootLock = &Scaleform::HeapMH::GlobalRootMH->RootLock;
    LeaveCriticalSection(&Scaleform::HeapMH::GlobalRootMH->RootLock.mLock.cs);
    *limHandlerOK = (*(int (__thiscall **)(void *, Scaleform::MemoryHeapMH *, unsigned int))(*(_DWORD *)this->pLimHandler
                                                                                           + 4))(
                      this->pLimHandler,
                      this->pHeap,
                      this->Footprint - this->Limit + 4096);
    EnterCriticalSection(&p_RootLock->mLock.cs);
    return 0;
  }
  else
  {
    *limHandlerOK = 0;
    v6 = Scaleform::HeapMH::RootMH::AllocPage(Scaleform::HeapMH::GlobalRootMH, this->pHeap);
    v7 = (Scaleform::HeapMH::PageMH *)v6;
    if ( v6 )
    {
      PageIndex = Scaleform::HeapMH::RootMH::GetPageIndex(Scaleform::HeapMH::GlobalRootMH, v6);
      Scaleform::HeapMH::AllocBitSet2MH::InitPage(&this->Allocator, v7, PageIndex);
      this->Footprint += 4096;
      v7->pNext = this->Pages.Root.pNext;
      v7->pPrev = (Scaleform::HeapMH::PageMH *)&this->Pages;
      this->Pages.Root.pNext->pPrev = v7;
      this->Pages.Root.pNext = v7;
      *limHandlerOK = 1;
    }
    return v7;
  }
}
