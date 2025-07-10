void __thiscall Scaleform::GFx::AS3::IntervalTimer::IntervalTimer(
        Scaleform::GFx::AS3::IntervalTimer *this,
        Scaleform::GFx::AS3::Value *function,
        unsigned int delay,
        bool timeOut)
{
  __int64 v5; // rax

  this->__vftable = (Scaleform::GFx::AS3::IntervalTimer_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->__vftable = (Scaleform::GFx::AS3::IntervalTimer_vtbl *)&Scaleform::GFx::AS3::IntervalTimer::`vftable';
  this->Function = *function;
  if ( (function->Flags & 0x1F) > 9 )
  {
    if ( (function->Flags & 0x200) != 0 )
      ++function->Bonus.pWeakProxy->RefCount;
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(function);
  }
  v5 = 1000LL * delay;
  this->TimerObj.pObject = 0;
  this->Params.Data.Data = 0;
  this->Params.Data.Size = 0;
  this->Params.Data.Policy.Capacity = 0;
  LODWORD(this->Interval) = v5;
  this->Timeout = timeOut;
  this->CurrentCount = 0;
  this->RepeatCount = 0;
  HIDWORD(this->Interval) = HIDWORD(v5);
  LODWORD(this->InvokeTime) = 0;
  HIDWORD(this->InvokeTime) = 0;
  this->Id = 0;
  this->Active = 1;
}
