Scaleform::HeapMH::PageMH *__thiscall Scaleform::HeapMH::AllocEngineMH::allocPageUnlocked(
        Scaleform::HeapMH::AllocEngineMH *this,
        bool *limHandlerOK)
{
  unsigned int Limit; // edx
  unsigned int Footprint; // eax
  void *pLimHandler; // ecx
  Scaleform::LockSafe *p_RootLock; // ebx
  const Scaleform::HeapMH::PageMH *v8; // eax
  Scaleform::HeapMH::PageMH *v9; // esi
  unsigned int PageIndex; // eax

  Limit = this->Limit;
  if ( Limit && (Footprint = this->Footprint, Footprint + 4096 > Limit) && (pLimHandler = this->pLimHandler) != 0 )
  {
    *limHandlerOK = (*(int (__thiscall **)(void *, Scaleform::MemoryHeapMH *, unsigned int))(*(_DWORD *)pLimHandler + 4))(
                      pLimHandler,
                      this->pHeap,
                      Footprint - Limit + 4096);
    return 0;
  }
  else
  {
    *limHandlerOK = 0;
    p_RootLock = &Scaleform::HeapMH::GlobalRootMH->RootLock;
    EnterCriticalSection(&Scaleform::HeapMH::GlobalRootMH->RootLock.mLock.cs);
    v8 = Scaleform::HeapMH::RootMH::AllocPage(Scaleform::HeapMH::GlobalRootMH, this->pHeap);
    v9 = (Scaleform::HeapMH::PageMH *)v8;
    if ( v8 )
    {
      PageIndex = Scaleform::HeapMH::RootMH::GetPageIndex(Scaleform::HeapMH::GlobalRootMH, v8);
      Scaleform::HeapMH::AllocBitSet2MH::InitPage(&this->Allocator, v9, PageIndex);
      this->Footprint += 4096;
      v9->pNext = this->Pages.Root.pNext;
      v9->pPrev = (Scaleform::HeapMH::PageMH *)&this->Pages;
      this->Pages.Root.pNext->pPrev = v9;
      this->Pages.Root.pNext = v9;
      *limHandlerOK = 1;
    }
    LeaveCriticalSection(&p_RootLock->mLock.cs);
    return v9;
  }
}
