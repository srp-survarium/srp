void __thiscall Scaleform::MemoryHeapMH::Release(Scaleform::MemoryHeapMH *this)
{
  Scaleform::MemoryHeap *pParent; // edi
  _RTL_CRITICAL_SECTION *p_cs; // ebx
  Scaleform::LockSafe *p_RootLock; // ebp
  Scaleform::LockSafe *v6; // edi

  pParent = this->Info.pParent;
  if ( pParent )
  {
    p_cs = &pParent->HeapLock.cs;
    EnterCriticalSection(&pParent->HeapLock.cs);
    p_RootLock = &Scaleform::HeapMH::GlobalRootMH->RootLock;
    EnterCriticalSection(&Scaleform::HeapMH::GlobalRootMH->RootLock.mLock.cs);
    if ( this->RefCount-- == 1 )
    {
      this->dumpMemoryLeaks(this);
      this->pPrev->Scaleform::MemoryHeap::pNext = this->pNext;
      this->pNext->Scaleform::MemoryHeap::pPrev = this->pPrev;
      Scaleform::HeapMH::RootMH::DestroyHeap(Scaleform::HeapMH::GlobalRootMH, this);
    }
    else
    {
      pParent = 0;
    }
    LeaveCriticalSection(&p_RootLock->mLock.cs);
    LeaveCriticalSection(p_cs);
    if ( pParent )
      pParent->Release(pParent);
  }
  else
  {
    v6 = &Scaleform::HeapMH::GlobalRootMH->RootLock;
    EnterCriticalSection(&Scaleform::HeapMH::GlobalRootMH->RootLock.mLock.cs);
    --this->RefCount;
    LeaveCriticalSection(&v6->mLock.cs);
  }
}
