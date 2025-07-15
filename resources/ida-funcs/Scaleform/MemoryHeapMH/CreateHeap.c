Scaleform::MemoryHeapMH *__thiscall Scaleform::MemoryHeapMH::CreateHeap(
        Scaleform::MemoryHeapMH *this,
        char *name,
        const Scaleform::MemoryHeap::HeapDesc *desc)
{
  Scaleform::LockSafe *p_RootLock; // ebx
  Scaleform::MemoryHeapMH *Heap; // esi

  p_RootLock = &Scaleform::HeapMH::GlobalRootMH->RootLock;
  EnterCriticalSection(&Scaleform::HeapMH::GlobalRootMH->RootLock.mLock.cs);
  Heap = Scaleform::HeapMH::RootMH::CreateHeap(Scaleform::HeapMH::GlobalRootMH, name, this, desc);
  if ( Heap )
    ++this->RefCount;
  LeaveCriticalSection(&p_RootLock->mLock.cs);
  if ( Heap )
  {
    EnterCriticalSection(&this->HeapLock.cs);
    Heap->pPrev = this->ChildHeaps.Root.Scaleform::MemoryHeap::pPrev;
    Heap->pNext = (Scaleform::MemoryHeap *)&this->Info.pName;
    this->ChildHeaps.Root.Scaleform::MemoryHeap::pPrev->Scaleform::MemoryHeap::pNext = Heap;
    this->ChildHeaps.Root.Scaleform::MemoryHeap::pPrev = Heap;
    LeaveCriticalSection(&this->HeapLock.cs);
  }
  return Heap;
}
