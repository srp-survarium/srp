unsigned __int8 *__thiscall Scaleform::MemoryHeapPT::Realloc(
        Scaleform::MemoryHeapPT *this,
        unsigned int oldPtr,
        unsigned int newSize)
{
  Scaleform::Heap::HeapSegment *pSegment; // ebp
  Scaleform::MemoryHeapPT *pHeap; // esi
  unsigned __int8 *v5; // eax
  unsigned __int8 *v6; // esi
  _RTL_CRITICAL_SECTION *p_cs; // [esp-8h] [ebp-14h]

  pSegment = Scaleform::HeapPT::GlobalPageTable->RootTable[oldPtr >> 20].pTable[(unsigned __int8)(oldPtr >> 12)].pSegment;
  pHeap = pSegment->pHeap;
  if ( !pHeap->UseLocks )
    return Scaleform::HeapPT::AllocEngine::Realloc(pHeap->pEngine, pSegment, (void *)oldPtr, newSize);
  EnterCriticalSection(&pHeap->HeapLock.cs);
  v5 = Scaleform::HeapPT::AllocEngine::Realloc(pHeap->pEngine, pSegment, (void *)oldPtr, newSize);
  p_cs = &pHeap->HeapLock.cs;
  v6 = v5;
  LeaveCriticalSection(p_cs);
  return v6;
}
