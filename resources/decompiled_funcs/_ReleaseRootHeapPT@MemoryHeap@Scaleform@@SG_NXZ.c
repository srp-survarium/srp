char __stdcall Scaleform::MemoryHeap::ReleaseRootHeapPT()
{
  Scaleform::LockSafe *p_RootLock; // esi
  bool v2; // bl

  if ( !Scaleform::HeapPT::GlobalRoot )
    return 1;
  p_RootLock = &Scaleform::HeapPT::GlobalRoot->RootLock;
  EnterCriticalSection(&Scaleform::HeapPT::GlobalRoot->RootLock.mLock.cs);
  if ( Scaleform::Memory::pGlobalHeap )
  {
    v2 = !Scaleform::Memory::pGlobalHeap->dumpMemoryLeaks(Scaleform::Memory::pGlobalHeap);
    Scaleform::Memory::pGlobalHeap->destroyItself(Scaleform::Memory::pGlobalHeap);
    Scaleform::Memory::pGlobalHeap = 0;
    LeaveCriticalSection(&p_RootLock->mLock.cs);
    return v2;
  }
  else
  {
    LeaveCriticalSection(&p_RootLock->mLock.cs);
    return 1;
  }
}
