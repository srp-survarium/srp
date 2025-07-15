void *__thiscall Scaleform::MemoryHeapMH::reallocMem(
        Scaleform::MemoryHeapMH *this,
        Scaleform::HeapMH::PageMH *page,
        void *oldPtr,
        unsigned int newSize,
        bool globalLocked)
{
  void *result; // eax
  Scaleform::LockSafe *p_RootLock; // edi
  void *v8; // esi
  Scaleform::HeapMH::PageInfoMH newPageInfo; // [esp+10h] [ebp-Ch] BYREF

  result = Scaleform::HeapMH::AllocEngineMH::ReallocInPage(
             this->pEngine,
             page,
             oldPtr,
             newSize,
             &newPageInfo,
             globalLocked);
  if ( !result )
  {
    if ( globalLocked )
    {
      return Scaleform::HeapMH::AllocEngineMH::ReallocGeneral(this->pEngine, page, oldPtr, newSize, &newPageInfo, 1);
    }
    else
    {
      p_RootLock = &Scaleform::HeapMH::GlobalRootMH->RootLock;
      EnterCriticalSection(&Scaleform::HeapMH::GlobalRootMH->RootLock.mLock.cs);
      v8 = Scaleform::HeapMH::AllocEngineMH::ReallocGeneral(this->pEngine, page, oldPtr, newSize, &newPageInfo, 1);
      LeaveCriticalSection(&p_RootLock->mLock.cs);
      return v8;
    }
  }
  return result;
}
