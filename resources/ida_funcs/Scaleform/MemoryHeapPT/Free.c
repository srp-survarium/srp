void __thiscall Scaleform::MemoryHeapPT::Free(Scaleform::MemoryHeapPT *this, unsigned int ptr)
{
  Scaleform::Heap::HeapSegment *pSegment; // ebx
  Scaleform::MemoryHeapPT *pHeap; // esi

  if ( ptr )
  {
    pSegment = Scaleform::HeapPT::GlobalPageTable->RootTable[ptr >> 20].pTable[(unsigned __int8)(ptr >> 12)].pSegment;
    pHeap = pSegment->pHeap;
    if ( pHeap->UseLocks )
    {
      EnterCriticalSection(&pHeap->HeapLock.cs);
      Scaleform::HeapPT::AllocEngine::Free(pHeap->pEngine, pSegment, (void *)ptr);
      LeaveCriticalSection(&pHeap->HeapLock.cs);
    }
    else
    {
      Scaleform::HeapPT::AllocEngine::Free(pHeap->pEngine, pSegment, (void *)ptr);
    }
    if ( (void *)ptr == pHeap->pAutoRelease )
      pHeap->Release(pHeap);
  }
}
