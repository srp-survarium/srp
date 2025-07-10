void __thiscall Scaleform::MemoryHeapPT::VisitHeapSegments(
        Scaleform::MemoryHeapPT *this,
        Scaleform::Heap::SegVisitor *visitor)
{
  Scaleform::Lock *p_HeapLock; // edi

  p_HeapLock = &this->HeapLock;
  EnterCriticalSection(&this->HeapLock.cs);
  Scaleform::HeapPT::AllocEngine::VisitSegments(this->pEngine, visitor);
  LeaveCriticalSection(&p_HeapLock->cs);
}
