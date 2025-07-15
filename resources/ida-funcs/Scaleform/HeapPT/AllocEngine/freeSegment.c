void __thiscall Scaleform::HeapPT::AllocEngine::freeSegment(
        Scaleform::HeapPT::AllocEngine *this,
        Scaleform::Heap::HeapSegment *seg)
{
  unsigned int DataSize; // ebx
  void *pLimHandler; // ecx
  unsigned int v5; // edx
  Scaleform::SysAllocPaged *pSysAlloc; // ecx

  DataSize = seg->DataSize;
  pLimHandler = this->pLimHandler;
  if ( pLimHandler )
    (*(void (__thiscall **)(void *, Scaleform::MemoryHeapPT *, unsigned int))(*(_DWORD *)pLimHandler + 8))(
      pLimHandler,
      this->pHeap,
      seg->DataSize);
  this->Footprint -= DataSize;
  Scaleform::HeapPT::PageTable::UnmapRange(Scaleform::HeapPT::GlobalPageTable, (unsigned int)seg->pData, DataSize);
  v5 = 1 << LOBYTE(seg->Alignment);
  if ( (seg->UseCount & 0x80000000) == 0 )
  {
    if ( v5 <= 0x1000 )
      v5 = 4096;
    this->pSysAlloc->Free(this->pSysAlloc, seg->pData, DataSize, v5);
  }
  else
  {
    pSysAlloc = this->pSysAlloc;
    this->Footprint -= seg->UseCount & 0x7FFFFFFF;
    pSysAlloc->FreeSysDirect(
      pSysAlloc,
      &seg->pData[-(seg->UseCount & 0x7FFFFFFF)],
      (seg->UseCount & 0x7FFFFFFF) + DataSize,
      v5);
  }
  seg->pPrev->pNext = seg->pNext;
  seg->pNext->Scaleform::ListNode<Scaleform::Heap::HeapSegment>::$D955224E6C67FC6F5EB4FF8DAC5F01DE::pPrev = seg->pPrev;
  Scaleform::HeapPT::Bookkeeper::Free(this->pBookkeeper, (void *)seg, seg->SelfSize);
}
