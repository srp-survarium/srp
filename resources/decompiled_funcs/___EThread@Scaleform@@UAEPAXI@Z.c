Scaleform::Thread *__thiscall Scaleform::Thread::`vector deleting destructor'(Scaleform::Thread *this, char a2)
{
  void *ThreadHandle; // eax

  ThreadHandle = this->ThreadHandle;
  this->Scaleform::Waitable::Scaleform::RefCountBase<Scaleform::Waitable,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable = (Scaleform::Thread_vtbl *)&Scaleform::Thread::`vftable'{for `Scaleform::Waitable'};
  this->Scaleform::AcquireInterface::__vftable = (Scaleform::AcquireInterface_vtbl *)&Scaleform::Thread::`vftable'{for `Scaleform::AcquireInterface'};
  if ( ThreadHandle )
  {
    CloseHandle(ThreadHandle);
    this->ThreadHandle = 0;
  }
  this->ThreadHandle = 0;
  this->Scaleform::AcquireInterface::__vftable = (Scaleform::AcquireInterface_vtbl *)&Scaleform::AcquireInterface::`vftable';
  Scaleform::Waitable::~Waitable(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
