void __thiscall Scaleform::Semaphore::Semaphore(Scaleform::Semaphore *this, int maxValue, bool multiWait)
{
  Scaleform::Waitable::Waitable(this, multiWait);
  this->Scaleform::AcquireInterface::__vftable = (Scaleform::AcquireInterface_vtbl *)&Scaleform::AcquireInterface::`vftable';
  this->Scaleform::Waitable::Scaleform::RefCountBase<Scaleform::Waitable,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable = (Scaleform::Semaphore_vtbl *)&Scaleform::Semaphore::`vftable'{for `Scaleform::Waitable'};
  this->Scaleform::AcquireInterface::__vftable = (Scaleform::AcquireInterface_vtbl *)&Scaleform::Semaphore::`vftable'{for `Scaleform::AcquireInterface'};
  Scaleform::Mutex::Mutex(&this->ValueMutex, 1, 0);
  Scaleform::WaitCondition::WaitCondition(&this->ValueWaitCondition);
  this->MaxValue = maxValue;
  this->Value = 0;
}
