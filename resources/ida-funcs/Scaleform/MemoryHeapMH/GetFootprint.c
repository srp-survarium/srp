unsigned int __thiscall Scaleform::MemoryHeapMH::GetFootprint(Scaleform::MemoryHeapMH *this)
{
  Scaleform::Lock *p_HeapLock; // edi
  unsigned int Footprint; // esi

  p_HeapLock = &this->HeapLock;
  EnterCriticalSection(&this->HeapLock.cs);
  Footprint = this->pEngine->Footprint;
  LeaveCriticalSection(&p_HeapLock->cs);
  return Footprint;
}
