void __thiscall Scaleform::MemoryHeapPT::Release(Scaleform::MemoryHeapPT *this)
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
    p_RootLock = &Scaleform::HeapPT::GlobalRoot->RootLock;
    EnterCriticalSection(&Scaleform::HeapPT::GlobalRoot->RootLock.mLock.cs);
    if ( this->RefCount-- == 1 )
    {
      this->dumpMemoryLeaks(this);
      this->pPrev->Scaleform::MemoryHeap::pNext = this->pNext;
      this->pNext->Scaleform::MemoryHeap::pPrev = this->pPrev;
      Scaleform::HeapPT::HeapRoot::DestroyHeap(Scaleform::HeapPT::GlobalRoot, this);
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
    v6 = &Scaleform::HeapPT::GlobalRoot->RootLock;
    EnterCriticalSection(&Scaleform::HeapPT::GlobalRoot->RootLock.mLock.cs);
    --this->RefCount;
    LeaveCriticalSection(&v6->mLock.cs);
  }
}
