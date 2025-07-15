char __thiscall Scaleform::GFx::AS3::IntervalTimer::Invoke(
        Scaleform::GFx::AS3::IntervalTimer *this,
        Scaleform::GFx::MovieImpl *proot,
        float frameTime)
{
  Scaleform::AmpStats *v4; // esi
  Scaleform::AmpStats_vtbl *v5; // edi
  unsigned __int64 v6; // rax
  unsigned int TimeElapsed; // ebp
  unsigned int TimeElapsed_high; // edi
  char v10; // bl
  Scaleform::GFx::AS3::Instances::fl_utils::Timer *pObject; // ecx
  unsigned int RepeatCount; // eax
  Scaleform::GFx::AS3::VM *v13; // ebp
  unsigned int v14; // eax
  __int64 v15; // rax
  Scaleform::AmpStats *Stats; // esi
  Scaleform::AmpStats_vtbl *v17; // edi
  unsigned __int64 ProfileTicks; // rax
  unsigned int Size; // [esp-14h] [ebp-54h]
  Scaleform::GFx::AS3::Value *Data; // [esp-10h] [ebp-50h]
  unsigned int currentTime; // [esp+8h] [ebp-38h]
  Scaleform::AmpFunctionTimer _amp_timer_; // [esp+10h] [ebp-30h] BYREF
  Scaleform::GFx::AS3::Value result; // [esp+20h] [ebp-20h] BYREF
  Scaleform::GFx::AS3::Value _this; // [esp+30h] [ebp-10h] BYREF

  Scaleform::AmpFunctionTimer::AmpFunctionTimer(
    &_amp_timer_,
    proot->AdvanceStats.pObject,
    "IntervalTimer::Invoke",
    Amp_Profile_Level_Medium,
    Amp_Native_Function_Id_Invalid);
  if ( this->Active )
  {
    TimeElapsed = proot->TimeElapsed;
    TimeElapsed_high = HIDWORD(proot->TimeElapsed);
    v10 = 0;
    currentTime = TimeElapsed;
    if ( __PAIR64__(TimeElapsed_high, TimeElapsed) >= this->InvokeTime )
    {
      pObject = this->TimerObj.pObject;
      if ( pObject )
      {
        RepeatCount = this->RepeatCount;
        if ( !RepeatCount || this->CurrentCount < RepeatCount )
        {
          ++this->CurrentCount;
          Scaleform::GFx::AS3::Instances::fl_utils::Timer::ExecuteEvent(pObject);
        }
      }
      else
      {
        v13 = (Scaleform::GFx::AS3::VM *)proot->pASMovieRoot.pObject[2].__vftable;
        Data = this->Params.Data.Data;
        Size = this->Params.Data.Size;
        _this.Flags = 0;
        _this.Bonus.pWeakProxy = 0;
        result.Flags = 0;
        result.Bonus.pWeakProxy = 0;
        Scaleform::GFx::AS3::VM::ExecuteInternalUnsafe(v13, &this->Function, &_this, &result, Size, Data, 0);
        if ( v13->HandleException )
          Scaleform::GFx::AS3::VM::OutputAndIgnoreException(v13);
        Scaleform::GFx::AS3::Value::~Value(&result);
        Scaleform::GFx::AS3::Value::~Value(&_this);
        TimeElapsed = currentTime;
      }
      if ( this->Timeout || (v14 = this->RepeatCount) != 0 && this->CurrentCount >= v14 )
      {
        this->Active = 0;
      }
      else
      {
        LODWORD(v15) = Scaleform::GFx::AS3::IntervalTimer::GetNextInterval(
                         this,
                         __PAIR64__(TimeElapsed_high, TimeElapsed),
                         (unsigned __int64)(frameTime * 1000000.0));
        if ( v15 )
        {
          this->InvokeTime += v15;
        }
        else
        {
          LODWORD(this->InvokeTime) = TimeElapsed;
          HIDWORD(this->InvokeTime) = TimeElapsed_high;
        }
      }
      v10 = 1;
    }
    Stats = _amp_timer_.Stats;
    if ( _amp_timer_.Stats )
    {
      v17 = _amp_timer_.Stats->__vftable;
      ProfileTicks = Scaleform::Timer::GetProfileTicks();
      ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))v17->NativePopCallstack)(
        Stats,
        ProfileTicks - LODWORD(_amp_timer_.StartTicks),
        (ProfileTicks - _amp_timer_.StartTicks) >> 32);
    }
    return v10;
  }
  else
  {
    v4 = _amp_timer_.Stats;
    if ( _amp_timer_.Stats )
    {
      v5 = _amp_timer_.Stats->__vftable;
      v6 = Scaleform::Timer::GetProfileTicks();
      ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))v5->NativePopCallstack)(
        v4,
        v6 - LODWORD(_amp_timer_.StartTicks),
        (v6 - _amp_timer_.StartTicks) >> 32);
    }
    return 0;
  }
}
