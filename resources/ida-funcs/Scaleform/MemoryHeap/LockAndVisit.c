void __thiscall Scaleform::MemoryHeap::LockAndVisit(
        Scaleform::MemoryHeap *this,
        Scaleform::MemoryHeap::HeapVisitor *visitor)
{
  Scaleform::Lock *p_HeapLock; // edi

  p_HeapLock = &this->HeapLock;
  EnterCriticalSection(&this->HeapLock.cs);
  visitor->Visit(visitor, 0, this);
  LeaveCriticalSection(&p_HeapLock->cs);
}
