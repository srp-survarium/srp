char __thiscall Scaleform::MemoryHeapPT::GetStats(Scaleform::MemoryHeapPT *this, Scaleform::StatBag *bag)
{
  Scaleform::Lock *p_HeapLock; // ebx
  Scaleform::MemoryHeap *pNext; // edi
  Scaleform::List<Scaleform::MemoryHeap,Scaleform::MemoryHeap> *p_ChildHeaps; // esi
  int v6; // eax
  Scaleform::HeapPT::HeapOtherStats otherStats; // [esp+Ch] [ebp-10h] BYREF

  p_HeapLock = &this->HeapLock;
  EnterCriticalSection(&this->HeapLock.cs);
  Scaleform::HeapPT::AllocEngine::GetFootprint(this->pEngine);
  Scaleform::HeapPT::AllocEngine::GetUsedSpace(this->pEngine);
  Scaleform::HeapPT::AllocEngine::GetHeapOtherStats(this->pEngine, &otherStats);
  otherStats.Bookkeeping += this->SelfSize;
  pNext = this->ChildHeaps.Root.pNext;
  p_ChildHeaps = &this->ChildHeaps;
  while ( 1 )
  {
    v6 = p_ChildHeaps ? (int)&p_ChildHeaps[-1].Root.4 : 0;
    if ( pNext == (Scaleform::MemoryHeap *)v6 )
      break;
    if ( (pNext->Info.Desc.Flags & 0x1000) == 0 )
      pNext->GetTotalFootprint(pNext);
    pNext = pNext->pNext;
  }
  LeaveCriticalSection(&p_HeapLock->cs);
  return 1;
}
