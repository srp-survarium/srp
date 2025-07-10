void __thiscall Scaleform::MemoryHeapMH::SetLimit(Scaleform::MemoryHeapMH *this, unsigned int newLimit)
{
  Scaleform::Lock *p_HeapLock; // edi
  unsigned int Footprint; // eax

  p_HeapLock = &this->HeapLock;
  EnterCriticalSection(&this->HeapLock.cs);
  Footprint = newLimit;
  if ( newLimit < this->Info.Desc.Limit && newLimit < this->pEngine->Footprint )
    Footprint = this->pEngine->Footprint;
  this->pEngine->Limit = Footprint;
  this->Info.Desc.Limit = Footprint;
  LeaveCriticalSection(&p_HeapLock->cs);
}
