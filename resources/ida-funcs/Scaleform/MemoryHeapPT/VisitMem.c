void __thiscall Scaleform::MemoryHeapPT::VisitMem(
        Scaleform::MemoryHeapPT *this,
        Scaleform::Heap::MemVisitor *visitor,
        unsigned int flags)
{
  Scaleform::Lock *p_HeapLock; // edi

  p_HeapLock = &this->HeapLock;
  EnterCriticalSection(&this->HeapLock.cs);
  Scaleform::HeapPT::AllocEngine::VisitMem(this->pEngine, visitor, flags);
  LeaveCriticalSection(&p_HeapLock->cs);
}
