void __thiscall Scaleform::MemoryHeapPT::AddRef(Scaleform::MemoryHeapPT *this)
{
  Scaleform::LockSafe *p_RootLock; // edi

  p_RootLock = &Scaleform::HeapPT::GlobalRoot->RootLock;
  EnterCriticalSection(&Scaleform::HeapPT::GlobalRoot->RootLock.mLock.cs);
  ++this->RefCount;
  LeaveCriticalSection(&p_RootLock->mLock.cs);
}
