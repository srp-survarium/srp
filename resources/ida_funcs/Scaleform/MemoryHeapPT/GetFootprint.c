unsigned int __thiscall Scaleform::MemoryHeapPT::GetFootprint(Scaleform::MemoryHeapPT *this)
{
  Scaleform::Lock *p_HeapLock; // edi
  unsigned int Footprint; // esi

  p_HeapLock = &this->HeapLock;
  EnterCriticalSection(&this->HeapLock.cs);
  Footprint = Scaleform::HeapPT::AllocEngine::GetFootprint(this->pEngine);
  LeaveCriticalSection(&p_HeapLock->cs);
  return Footprint;
}
