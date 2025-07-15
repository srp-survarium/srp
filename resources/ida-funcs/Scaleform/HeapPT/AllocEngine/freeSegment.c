void __thiscall Scaleform::HeapPT::AllocEngine::freeSegment(Scaleform::HeapPT::AllocEngine *this, unsigned int seg)
{
  unsigned int v2; // ebx
  void *pLimHandler; // ecx
  unsigned int v5; // edx
  Scaleform::SysAllocPaged *pSysAlloc; // ecx

  v2 = *(_DWORD *)(seg + 24);
  pLimHandler = this->pLimHandler;
  if ( pLimHandler )
    (*(void (__thiscall **)(void *, Scaleform::MemoryHeapPT *, unsigned int))(*(_DWORD *)pLimHandler + 8))(
      pLimHandler,
      this->pHeap,
      *(_DWORD *)(seg + 24));
  this->Footprint -= v2;
  Scaleform::HeapPT::PageTable::UnmapRange(Scaleform::HeapPT::GlobalPageTable, *(_DWORD *)(seg + 28), v2);
  v5 = 1 << *(_BYTE *)(seg + 14);
  if ( *(int *)(seg + 16) >= 0 )
  {
    if ( v5 <= 0x1000 )
      v5 = 4096;
    this->pSysAlloc->Free(this->pSysAlloc, *(void **)(seg + 28), v2, v5);
  }
  else
  {
    pSysAlloc = this->pSysAlloc;
    this->Footprint -= *(_DWORD *)(seg + 16) & 0x7FFFFFFF;
    pSysAlloc->FreeSysDirect(
      pSysAlloc,
      (void *)(*(_DWORD *)(seg + 28) - (*(_DWORD *)(seg + 16) & 0x7FFFFFFF)),
      (*(_DWORD *)(seg + 16) & 0x7FFFFFFF) + v2,
      v5);
  }
  *(_DWORD *)(*(_DWORD *)seg + 4) = *(_DWORD *)(seg + 4);
  **(_DWORD **)(seg + 4) = *(_DWORD *)seg;
  Scaleform::HeapPT::Bookkeeper::Free(this->pBookkeeper, seg, *(_DWORD *)(seg + 8));
}
