unsigned int __thiscall Scaleform::MemoryHeapMH::GetUsedSpace(Scaleform::MemoryHeapMH *this)
{
  Scaleform::Lock *p_HeapLock; // edi
  unsigned int UsedSpace; // esi

  p_HeapLock = &this->HeapLock;
  EnterCriticalSection(&this->HeapLock.cs);
  UsedSpace = this->pEngine->UsedSpace;
  LeaveCriticalSection(&p_HeapLock->cs);
  return UsedSpace;
}
