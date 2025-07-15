unsigned int __thiscall Scaleform::MemoryHeapPT::GetTotalFootprint(Scaleform::MemoryHeapPT *this)
{
  Scaleform::Lock *p_HeapLock; // ebp
  unsigned int Footprint; // ebx
  Scaleform::MemoryHeap *pNext; // edi
  Scaleform::List<Scaleform::MemoryHeap,Scaleform::MemoryHeap> *p_ChildHeaps; // esi
  int v6; // eax
  int v7; // eax

  p_HeapLock = &this->HeapLock;
  EnterCriticalSection(&this->HeapLock.cs);
  Footprint = 0;
  if ( (this->Info.Desc.Flags & 0x1000) == 0 )
    Footprint = Scaleform::HeapPT::AllocEngine::GetFootprint(this->pEngine);
  pNext = this->ChildHeaps.Root.pNext;
  p_ChildHeaps = &this->ChildHeaps;
  while ( 1 )
  {
    v6 = p_ChildHeaps ? (int)&p_ChildHeaps[-1].Root.4 : 0;
    if ( pNext == (Scaleform::MemoryHeap *)v6 )
      break;
    v7 = pNext->GetTotalFootprint(pNext);
    pNext = pNext->pNext;
    Footprint += v7;
  }
  LeaveCriticalSection(&p_HeapLock->cs);
  return Footprint;
}
