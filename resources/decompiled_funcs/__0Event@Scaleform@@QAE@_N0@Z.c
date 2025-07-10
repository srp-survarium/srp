void __thiscall Scaleform::Event::Event(Scaleform::Event *this, volatile bool setInitially, bool multiWait)
{
  Scaleform::Waitable::Waitable(this, multiWait);
  this->Scaleform::AcquireInterface::__vftable = (Scaleform::AcquireInterface_vtbl *)&Scaleform::AcquireInterface::`vftable';
  this->Scaleform::Waitable::Scaleform::RefCountBase<Scaleform::Waitable,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable = (Scaleform::Event_vtbl *)&Scaleform::Event::`vftable'{for `Scaleform::Waitable'};
  this->Scaleform::AcquireInterface::__vftable = (Scaleform::AcquireInterface_vtbl *)&Scaleform::Event::`vftable'{for `Scaleform::AcquireInterface'};
  Scaleform::Mutex::Mutex(&this->StateMutex, 1, 0);
  Scaleform::WaitCondition::WaitCondition(&this->StateWaitCondition);
  this->State = setInitially;
  this->Temporary = 0;
}
