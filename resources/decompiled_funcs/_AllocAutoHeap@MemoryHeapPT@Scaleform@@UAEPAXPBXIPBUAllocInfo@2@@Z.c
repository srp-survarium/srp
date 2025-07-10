void *__thiscall Scaleform::MemoryHeapPT::AllocAutoHeap(
        Scaleform::MemoryHeapPT *this,
        unsigned int thisPtr,
        unsigned int size,
        const Scaleform::AllocInfo *info)
{
  Scaleform::MemoryHeapPT *pHeap; // esi
  void *v5; // eax
  void *v6; // esi
  _RTL_CRITICAL_SECTION *p_cs; // [esp-8h] [ebp-Ch]

  pHeap = Scaleform::HeapPT::GlobalPageTable->RootTable[thisPtr >> 20].pTable[(unsigned __int8)(thisPtr >> 12)].pSegment->pHeap;
  if ( !pHeap->UseLocks )
    return Scaleform::HeapPT::AllocEngine::Alloc(pHeap->pEngine, size);
  EnterCriticalSection(&pHeap->HeapLock.cs);
  v5 = Scaleform::HeapPT::AllocEngine::Alloc(pHeap->pEngine, size);
  p_cs = &pHeap->HeapLock.cs;
  v6 = v5;
  LeaveCriticalSection(p_cs);
  return v6;
}
