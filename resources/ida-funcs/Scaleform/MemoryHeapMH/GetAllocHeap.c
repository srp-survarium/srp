Scaleform::MemoryHeapMH *__thiscall Scaleform::MemoryHeapMH::GetAllocHeap(
        Scaleform::MemoryHeapMH *this,
        unsigned int thisPtr)
{
  Scaleform::HeapMH::PageMH *v2; // eax
  Scaleform::LockSafe *p_RootLock; // edi
  unsigned int v5; // esi

  v2 = Scaleform::HeapMH::RootMH::ResolveAddress(Scaleform::HeapMH::GlobalRootMH, thisPtr);
  if ( v2 )
    return v2->pHeap;
  p_RootLock = &Scaleform::HeapMH::GlobalRootMH->RootLock;
  EnterCriticalSection(&Scaleform::HeapMH::GlobalRootMH->RootLock.mLock.cs);
  v5 = Scaleform::RadixTree<Scaleform::HeapMH::NodeMH,Scaleform::HeapMH::TreeNodeAccessor>::FindGrEq(
         &Scaleform::HeapMH::GlobalRootMH->HeapTree,
         thisPtr)->pHeap
     & 0xFFFFFFFC;
  LeaveCriticalSection(&p_RootLock->mLock.cs);
  return (Scaleform::MemoryHeapMH *)v5;
}
