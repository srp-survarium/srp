Scaleform::MemoryHeap *__stdcall Scaleform::MemoryHeap::CreateRootHeapPT(const Scaleform::MemoryHeap::HeapDesc *desc)
{
  Scaleform::MemoryHeap *result; // eax
  Scaleform::LockSafe *p_RootLock; // ebx
  Scaleform::MemoryHeap::HeapDesc d2; // [esp+0h] [ebp-20h] BYREF

  result = (Scaleform::MemoryHeap *)Scaleform::HeapPT::GlobalRoot;
  if ( Scaleform::HeapPT::GlobalRoot )
  {
    p_RootLock = &Scaleform::HeapPT::GlobalRoot->RootLock;
    EnterCriticalSection(&Scaleform::HeapPT::GlobalRoot->RootLock.mLock.cs);
    if ( Scaleform::Memory::pGlobalHeap )
    {
      LeaveCriticalSection(&p_RootLock->mLock.cs);
      return 0;
    }
    else
    {
      qmemcpy((void *)&d2, desc, sizeof(d2));
      d2.HeapId = 1;
      Scaleform::Memory::pGlobalHeap = Scaleform::HeapPT::HeapRoot::CreateHeap(
                                         Scaleform::HeapPT::GlobalRoot,
                                         "Global",
                                         0,
                                         &d2);
      LeaveCriticalSection(&p_RootLock->mLock.cs);
      return Scaleform::Memory::pGlobalHeap;
    }
  }
  return result;
}
