int __thiscall Scaleform::GFx::MovieImpl::AddIntervalTimer(
        Scaleform::GFx::MovieImpl *this,
        Scaleform::GFx::Resource *timer)
{
  Scaleform::Ptr<Scaleform::GFx::ASIntervalTimerIntf> *v3; // esi

  ((void (__thiscall *)(Scaleform::GFx::Resource *, int))timer->__vftable[1].GetResourceReport)(
    timer,
    ++this->LastIntervalTimerId);
  Scaleform::RefCountImpl::AddRef(timer);
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ASIntervalTimerIntf>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ASIntervalTimerIntf>,327>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    &this->IntervalTimers.Data,
    &this->IntervalTimers,
    this->IntervalTimers.Data.Size + 1);
  v3 = &this->IntervalTimers.Data.Data[this->IntervalTimers.Data.Size - 1];
  if ( &this->IntervalTimers.Data.Data[this->IntervalTimers.Data.Size] != (Scaleform::Ptr<Scaleform::GFx::ASIntervalTimerIntf> *)4 )
  {
    Scaleform::RefCountImpl::AddRef(timer);
    v3->pObject = (Scaleform::GFx::ASIntervalTimerIntf *)timer;
  }
  Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)timer);
  return this->LastIntervalTimerId;
}
