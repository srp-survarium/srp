void __thiscall Scaleform::MemoryHeapMH::AddRef(Scaleform::MemoryHeapMH *this)
{
  Scaleform::LockSafe *p_RootLock; // edi

  p_RootLock = &Scaleform::HeapMH::GlobalRootMH->RootLock;
  EnterCriticalSection(&Scaleform::HeapMH::GlobalRootMH->RootLock.mLock.cs);
  ++this->RefCount;
  LeaveCriticalSection(&p_RootLock->mLock.cs);
}
