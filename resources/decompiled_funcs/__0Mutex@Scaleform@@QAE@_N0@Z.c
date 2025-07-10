void __thiscall Scaleform::Mutex::Mutex(Scaleform::Mutex *this, bool recursive, bool multiWait)
{
  Scaleform::MutexImpl *v4; // eax
  Scaleform::MutexImpl *v5; // edi
  bool v6; // zf

  Scaleform::Waitable::Waitable(this, multiWait);
  this->Scaleform::AcquireInterface::__vftable = (Scaleform::AcquireInterface_vtbl *)&Scaleform::AcquireInterface::`vftable';
  this->Scaleform::Waitable::Scaleform::RefCountBase<Scaleform::Waitable,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable = (Scaleform::Mutex_vtbl *)&Scaleform::Mutex::`vftable'{for `Scaleform::Waitable'};
  this->Scaleform::AcquireInterface::__vftable = (Scaleform::AcquireInterface_vtbl *)&Scaleform::Mutex::`vftable'{for `Scaleform::AcquireInterface'};
  v4 = (Scaleform::MutexImpl *)Scaleform::Memory::pGlobalHeap->Alloc(Scaleform::Memory::pGlobalHeap, 20, 0);
  v5 = v4;
  if ( v4 )
  {
    v4->AreadyLockedAcquire.__vftable = (Scaleform::Mutex_AreadyLockedAcquireInterface_vtbl *)&Scaleform::Mutex_AreadyLockedAcquireInterface::`vftable';
    v4->AreadyLockedAcquire.pMutex = 0;
    v4->Recursive = recursive;
    v6 = !v4->Recursive;
    v4->AreadyLockedAcquire.pMutex = this;
    v4->LockCount = 0;
    if ( v6 )
      v4->hMutexOrSemaphore = CreateSemaphoreA(0, 1, 1, 0);
    else
      v4->hMutexOrSemaphore = CreateMutexA(0, 0, 0);
    this->pImpl = v5;
  }
  else
  {
    this->pImpl = 0;
  }
}
