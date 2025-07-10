void __thiscall Scaleform::MemoryHeapPT::releaseCachedMem(Scaleform::MemoryHeapPT *this)
{
  Scaleform::Lock *p_HeapLock; // ebp
  Scaleform::MemoryHeap *i; // esi
  char **v4; // eax

  p_HeapLock = &this->HeapLock;
  EnterCriticalSection(&this->HeapLock.cs);
  for ( i = this->ChildHeaps.Root.pNext; ; i = i->pNext )
  {
    v4 = this == (Scaleform::MemoryHeapPT *)-68 ? 0 : &this->Info.pName;
    if ( i == (Scaleform::MemoryHeap *)v4 )
      break;
    i->releaseCachedMem(i);
  }
  Scaleform::HeapPT::AllocEngine::ReleaseCachedMem(this->pEngine);
  LeaveCriticalSection(&p_HeapLock->cs);
}
