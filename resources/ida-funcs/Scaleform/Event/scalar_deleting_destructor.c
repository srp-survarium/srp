Scaleform::Event *__thiscall Scaleform::Event::`scalar deleting destructor'(Scaleform::Event *this, char a2)
{
  this->Scaleform::Waitable::Scaleform::RefCountBase<Scaleform::Waitable,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable = (Scaleform::Event_vtbl *)&Scaleform::Event::`vftable'{for `Scaleform::Waitable'};
  this->Scaleform::AcquireInterface::__vftable = (Scaleform::AcquireInterface_vtbl *)&Scaleform::Event::`vftable'{for `Scaleform::AcquireInterface'};
  Scaleform::WaitCondition::~WaitCondition(&this->StateWaitCondition);
  Scaleform::Mutex::~Mutex(&this->StateMutex);
  this->Scaleform::AcquireInterface::__vftable = (Scaleform::AcquireInterface_vtbl *)&Scaleform::AcquireInterface::`vftable';
  Scaleform::Waitable::~Waitable(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
