void __thiscall Scaleform::MemoryHeapPT::Free(
        Scaleform::MemoryHeapPT *this,
        Scaleform::HeapPT::AllocEngine::TinyBlock *ptr)
{
  Scaleform::Heap::HeapSegment *pSegment; // ebx
  Scaleform::MemoryHeapPT *pHeap; // esi

  if ( ptr )
  {
    pSegment = Scaleform::HeapPT::GlobalPageTable->RootTable[(unsigned int)ptr >> 20].pTable[(unsigned __int8)((unsigned int)ptr >> 12)].pSegment;
    pHeap = pSegment->pHeap;
    if ( pHeap->UseLocks )
    {
      EnterCriticalSection(&pHeap->HeapLock.cs);
      Scaleform::HeapPT::AllocEngine::Free(pHeap->pEngine, pSegment, ptr);
      LeaveCriticalSection(&pHeap->HeapLock.cs);
    }
    else
    {
      Scaleform::HeapPT::AllocEngine::Free(pHeap->pEngine, pSegment, ptr);
    }
    if ( ptr == pHeap->pAutoRelease )
      pHeap->Release(pHeap);
  }
}
