Scaleform::MemoryHeapPT *__thiscall Scaleform::MemoryHeapPT::CreateHeap(
        Scaleform::MemoryHeapPT *this,
        const char *name,
        const Scaleform::MemoryHeap::HeapDesc *desc)
{
  Scaleform::LockSafe *p_RootLock; // ebx
  Scaleform::MemoryHeapPT *Heap; // esi

  p_RootLock = &Scaleform::HeapPT::GlobalRoot->RootLock;
  EnterCriticalSection(&Scaleform::HeapPT::GlobalRoot->RootLock.mLock.cs);
  Heap = Scaleform::HeapPT::HeapRoot::CreateHeap(Scaleform::HeapPT::GlobalRoot, name, this, desc);
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
