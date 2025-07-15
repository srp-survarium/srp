Scaleform::Semaphore *__thiscall Scaleform::Semaphore::`vector deleting destructor'(
        Scaleform::Semaphore *this,
        char a2)
{
  this->Scaleform::Waitable::Scaleform::RefCountBase<Scaleform::Waitable,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable = (Scaleform::Semaphore_vtbl *)&Scaleform::Semaphore::`vftable'{for `Scaleform::Waitable'};
  this->Scaleform::AcquireInterface::__vftable = (Scaleform::AcquireInterface_vtbl *)&Scaleform::Semaphore::`vftable'{for `Scaleform::AcquireInterface'};
  Scaleform::WaitCondition::~WaitCondition(&this->ValueWaitCondition);
  Scaleform::Mutex::~Mutex(&this->ValueMutex);
  this->Scaleform::AcquireInterface::__vftable = (Scaleform::AcquireInterface_vtbl *)&Scaleform::AcquireInterface::`vftable';
  Scaleform::Waitable::~Waitable(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}


Scaleform::Semaphore *__thiscall Scaleform::Semaphore::`vector deleting destructor'(char *this, char a2)
{
  return Scaleform::Semaphore::`vector deleting destructor'((Scaleform::Semaphore *)(this - 12), a2);
}
