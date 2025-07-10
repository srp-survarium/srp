void __thiscall Scaleform::Waitable::HandlerArray::Release(Scaleform::Waitable::HandlerArray *this)
{
  if ( InterlockedExchangeAdd(&this->RefCount.Value, -1) == 1 && this )
  {
    Scaleform::Lock::~Lock(&this->HandlersLock);
    if ( this->Handlers.Data.Data )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->Handlers.Data.Data);
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  }
}
