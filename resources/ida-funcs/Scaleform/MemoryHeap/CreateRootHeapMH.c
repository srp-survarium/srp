Scaleform::MemoryHeap *__stdcall Scaleform::MemoryHeap::CreateRootHeapMH(const Scaleform::MemoryHeap::HeapDesc *desc)
{
  Scaleform::MemoryHeap *result; // eax
  Scaleform::LockSafe *p_RootLock; // ebx
  Scaleform::MemoryHeap::HeapDesc desca; // [esp+0h] [ebp-20h] BYREF

  result = (Scaleform::MemoryHeap *)Scaleform::HeapMH::GlobalRootMH;
  if ( Scaleform::HeapMH::GlobalRootMH )
  {
    p_RootLock = &Scaleform::HeapMH::GlobalRootMH->RootLock;
    EnterCriticalSection(&Scaleform::HeapMH::GlobalRootMH->RootLock.mLock.cs);
    if ( Scaleform::Memory::pGlobalHeap )
    {
      LeaveCriticalSection(&p_RootLock->mLock.cs);
      return 0;
    }
    else
    {
      qmemcpy((void *)&desca, desc, sizeof(desca));
      desca.HeapId = 1;
      Scaleform::Memory::pGlobalHeap = Scaleform::HeapMH::RootMH::CreateHeap(
                                         Scaleform::HeapMH::GlobalRootMH,
                                         "Global",
                                         0,
                                         &desca);
      LeaveCriticalSection(&p_RootLock->mLock.cs);
      return Scaleform::Memory::pGlobalHeap;
    }
  }
  return result;
}
