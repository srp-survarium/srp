void *__thiscall Scaleform::MemoryHeapMH::AllocSysDirect(Scaleform::MemoryHeapMH *this, unsigned int size)
{
  Scaleform::LockSafe *p_RootLock; // esi
  void *v3; // edi

  p_RootLock = &Scaleform::HeapMH::GlobalRootMH->RootLock;
  EnterCriticalSection(&Scaleform::HeapMH::GlobalRootMH->RootLock.mLock.cs);
  v3 = Scaleform::HeapMH::GlobalRootMH->pSysAlloc->Alloc(Scaleform::HeapMH::GlobalRootMH->pSysAlloc, size, 4);
  LeaveCriticalSection(&p_RootLock->mLock.cs);
  return v3;
}
