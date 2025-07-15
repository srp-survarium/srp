Scaleform::MemoryHeap *__stdcall Scaleform::MemoryHeap::CreateRootHeapPT(const Scaleform::MemoryHeap::HeapDesc *desc)
{
  Scaleform::MemoryHeap *result; // eax
  Scaleform::LockSafe *p_RootLock; // ebx
  Scaleform::MemoryHeap::HeapDesc desca; // [esp+0h] [ebp-20h] BYREF

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
      qmemcpy((void *)&desca, desc, sizeof(desca));
      desca.HeapId = 1;
      Scaleform::Memory::pGlobalHeap = Scaleform::HeapPT::HeapRoot::CreateHeap(
                                         Scaleform::HeapPT::GlobalRoot,
                                         "Global",
                                         0,
                                         (Scaleform::SysAllocPaged *)&desca);
      LeaveCriticalSection(&p_RootLock->mLock.cs);
      return Scaleform::Memory::pGlobalHeap;
    }
  }
  return result;
}
