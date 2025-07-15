void __thiscall Scaleform::MemoryHeapMH::SetLimitHandler(
        Scaleform::MemoryHeapMH *this,
        Scaleform::MemoryHeap::LimitHandler *handler)
{
  Scaleform::Lock *p_HeapLock; // edi

  p_HeapLock = &this->HeapLock;
  EnterCriticalSection(&this->HeapLock.cs);
  this->pEngine->pLimHandler = handler;
  LeaveCriticalSection(&p_HeapLock->cs);
}
