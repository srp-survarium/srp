void __thiscall Scaleform::Waitable::~Waitable(Scaleform::Waitable *this)
{
  Scaleform::Waitable::HandlerArray *pHandlers; // esi

  pHandlers = this->pHandlers;
  this->__vftable = (Scaleform::Waitable_vtbl *)&Scaleform::Waitable::`vftable';
  if ( pHandlers && InterlockedExchangeAdd(&pHandlers->RefCount.Value, -1) == 1 )
  {
    Scaleform::Lock::~Lock(&pHandlers->HandlersLock);
    if ( pHandlers->Handlers.Data.Data )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pHandlers->Handlers.Data.Data);
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pHandlers);
  }
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
}
