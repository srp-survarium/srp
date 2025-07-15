void __thiscall Scaleform::MemoryHeapMH::getUserDebugStats(
        Scaleform::MemoryHeapMH *this,
        Scaleform::MemoryHeap::RootStats *stats)
{
  Scaleform::Lock *p_HeapLock; // ebp
  Scaleform::MemoryHeap *pNext; // edi
  Scaleform::List<Scaleform::MemoryHeap,Scaleform::MemoryHeap> *p_ChildHeaps; // esi
  int v6; // eax

  p_HeapLock = &this->HeapLock;
  EnterCriticalSection(&this->HeapLock.cs);
  if ( (this->Info.Desc.Flags & 0x1000) != 0 )
  {
    stats->UserDebugFootprint += this->pEngine->Footprint;
    stats->UserDebugUsedSpace += this->pEngine->UsedSpace;
  }
  pNext = this->ChildHeaps.Root.pNext;
  p_ChildHeaps = &this->ChildHeaps;
  while ( 1 )
  {
    v6 = p_ChildHeaps ? (int)&p_ChildHeaps[-1].Root.4 : 0;
    if ( pNext == (Scaleform::MemoryHeap *)v6 )
      break;
    pNext->getUserDebugStats(pNext, stats);
    pNext = pNext->pNext;
  }
  LeaveCriticalSection(&p_HeapLock->cs);
}
