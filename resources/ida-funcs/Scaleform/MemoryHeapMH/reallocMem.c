char *__thiscall Scaleform::MemoryHeapMH::reallocMem(
        Scaleform::MemoryHeapMH *this,
        Scaleform::HeapMH::PageMH *page,
        void *oldPtr,
        unsigned int newSize,
        bool globalLocked)
{
  char *result; // eax
  Scaleform::LockSafe *p_RootLock; // edi
  char *v8; // esi
  Scaleform::HeapMH::PageInfoMH newInfo; // [esp+10h] [ebp-Ch] BYREF

  result = (char *)Scaleform::HeapMH::AllocEngineMH::ReallocInPage(
                     this->pEngine,
                     page,
                     oldPtr,
                     newSize,
                     &newInfo,
                     globalLocked);
  if ( !result )
  {
    if ( globalLocked )
    {
      return Scaleform::HeapMH::AllocEngineMH::ReallocGeneral(
               this->pEngine,
               page,
               oldPtr,
               newSize,
               &newInfo,
               (Scaleform::LockSafe *)1);
    }
    else
    {
      p_RootLock = &Scaleform::HeapMH::GlobalRootMH->RootLock;
      EnterCriticalSection(&Scaleform::HeapMH::GlobalRootMH->RootLock.mLock.cs);
      v8 = Scaleform::HeapMH::AllocEngineMH::ReallocGeneral(
             this->pEngine,
             page,
             oldPtr,
             newSize,
             &newInfo,
             (Scaleform::LockSafe *)1);
      LeaveCriticalSection(&p_RootLock->mLock.cs);
      return v8;
    }
  }
  return result;
}
