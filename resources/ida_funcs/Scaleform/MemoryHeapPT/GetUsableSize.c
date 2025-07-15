unsigned int __thiscall Scaleform::MemoryHeapPT::GetUsableSize(Scaleform::MemoryHeapPT *this, unsigned int ptr)
{
  Scaleform::Heap::HeapSegment *pSegment; // ebp
  Scaleform::MemoryHeapPT *pHeap; // esi
  unsigned int UsableSize; // eax
  unsigned int v5; // esi
  _RTL_CRITICAL_SECTION *p_cs; // [esp-8h] [ebp-14h]

  pSegment = Scaleform::HeapPT::GlobalPageTable->RootTable[ptr >> 20].pTable[(unsigned __int8)(ptr >> 12)].pSegment;
  pHeap = pSegment->pHeap;
  if ( !pHeap->UseLocks )
    return Scaleform::HeapPT::AllocEngine::GetUsableSize(pHeap->pEngine, pSegment, (const void *)ptr);
  EnterCriticalSection(&pHeap->HeapLock.cs);
  UsableSize = Scaleform::HeapPT::AllocEngine::GetUsableSize(pHeap->pEngine, pSegment, (const void *)ptr);
  p_cs = &pHeap->HeapLock.cs;
  v5 = UsableSize;
  LeaveCriticalSection(p_cs);
  return v5;
}
