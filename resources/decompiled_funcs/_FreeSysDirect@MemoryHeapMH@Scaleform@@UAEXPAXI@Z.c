void __thiscall Scaleform::MemoryHeapMH::FreeSysDirect(Scaleform::MemoryHeapMH *this, void *ptr, unsigned int size)
{
  Scaleform::LockSafe *p_RootLock; // esi

  p_RootLock = &Scaleform::HeapMH::GlobalRootMH->RootLock;
  EnterCriticalSection(&Scaleform::HeapMH::GlobalRootMH->RootLock.mLock.cs);
  Scaleform::HeapMH::GlobalRootMH->pSysAlloc->Free(Scaleform::HeapMH::GlobalRootMH->pSysAlloc, ptr, size, 4u);
  LeaveCriticalSection(&p_RootLock->mLock.cs);
}
