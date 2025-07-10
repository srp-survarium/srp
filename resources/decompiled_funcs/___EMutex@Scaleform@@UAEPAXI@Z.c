Scaleform::Mutex *__thiscall Scaleform::Mutex::`vector deleting destructor'(Scaleform::Mutex *this, char a2)
{
  Scaleform::MutexImpl *pImpl; // edi

  pImpl = this->pImpl;
  this->Scaleform::Waitable::Scaleform::RefCountBase<Scaleform::Waitable,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable = (Scaleform::Mutex_vtbl *)&Scaleform::Mutex::`vftable'{for `Scaleform::Waitable'};
  this->Scaleform::AcquireInterface::__vftable = (Scaleform::AcquireInterface_vtbl *)&Scaleform::Mutex::`vftable'{for `Scaleform::AcquireInterface'};
  if ( pImpl )
  {
    CloseHandle(pImpl->hMutexOrSemaphore);
    pImpl->AreadyLockedAcquire.__vftable = (Scaleform::Mutex_AreadyLockedAcquireInterface_vtbl *)&Scaleform::AcquireInterface::`vftable';
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pImpl);
  }
  this->Scaleform::AcquireInterface::__vftable = (Scaleform::AcquireInterface_vtbl *)&Scaleform::AcquireInterface::`vftable';
  Scaleform::Waitable::~Waitable(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
