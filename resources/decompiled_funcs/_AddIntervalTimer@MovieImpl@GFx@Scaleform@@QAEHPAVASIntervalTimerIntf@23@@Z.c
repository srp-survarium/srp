int __thiscall Scaleform::GFx::MovieImpl::AddIntervalTimer(
        Scaleform::GFx::MovieImpl *this,
        Scaleform::GFx::ASIntervalTimerIntf *timer)
{
  Scaleform::Ptr<Scaleform::GFx::ASIntervalTimerIntf> *v3; // esi

  timer->SetId(timer, ++this->LastIntervalTimerId);
  Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)timer);
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ASIntervalTimerIntf>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ASIntervalTimerIntf>,327>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    &this->IntervalTimers.Data,
    &this->IntervalTimers,
    this->IntervalTimers.Data.Size + 1);
  v3 = &this->IntervalTimers.Data.Data[this->IntervalTimers.Data.Size - 1];
  if ( &this->IntervalTimers.Data.Data[this->IntervalTimers.Data.Size] != (Scaleform::Ptr<Scaleform::GFx::ASIntervalTimerIntf> *)4 )
  {
    Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)timer);
    v3->pObject = timer;
  }
  Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)timer);
  return this->LastIntervalTimerId;
}
