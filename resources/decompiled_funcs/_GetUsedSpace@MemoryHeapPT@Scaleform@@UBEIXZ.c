unsigned int __thiscall Scaleform::MemoryHeapPT::GetUsedSpace(Scaleform::MemoryHeapPT *this)
{
  Scaleform::Lock *p_HeapLock; // edi
  unsigned int UsedSpace; // esi

  p_HeapLock = &this->HeapLock;
  EnterCriticalSection(&this->HeapLock.cs);
  UsedSpace = Scaleform::HeapPT::AllocEngine::GetUsedSpace(this->pEngine);
  LeaveCriticalSection(&p_HeapLock->cs);
  return UsedSpace;
}
