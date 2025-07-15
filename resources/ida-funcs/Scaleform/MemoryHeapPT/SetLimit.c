void __thiscall Scaleform::MemoryHeapPT::SetLimit(Scaleform::MemoryHeapPT *this, unsigned int newLimit)
{
  Scaleform::Lock *p_HeapLock; // ebx
  unsigned int Footprint; // edi

  p_HeapLock = &this->HeapLock;
  EnterCriticalSection(&this->HeapLock.cs);
  Footprint = newLimit;
  if ( newLimit < this->Info.Desc.Limit && newLimit < Scaleform::HeapPT::AllocEngine::GetFootprint(this->pEngine) )
    Footprint = Scaleform::HeapPT::AllocEngine::GetFootprint(this->pEngine);
  this->Info.Desc.Limit = Scaleform::HeapPT::AllocEngine::SetLimit(this->pEngine, Footprint);
  LeaveCriticalSection(&p_HeapLock->cs);
}
