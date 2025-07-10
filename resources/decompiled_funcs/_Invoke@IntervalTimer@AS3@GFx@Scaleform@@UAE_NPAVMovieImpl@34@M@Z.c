bool __thiscall Scaleform::GFx::AS3::IntervalTimer::Invoke(
        Scaleform::GFx::AS3::IntervalTimer *this,
        Scaleform::GFx::MovieImpl *proot,
        float frameTime)
{
  bool v4; // al
  Scaleform::GFx::ASMovieRootBase *pObject; // edx
  unsigned int TimeElapsed; // ebx
  unsigned int TimeElapsed_high; // ebp
  Scaleform::GFx::AS3::Instances::fl_utils::Timer *v8; // ecx
  unsigned int RepeatCount; // eax
  Scaleform::GFx::AS3::VM *v10; // edi
  unsigned int v11; // eax
  int NextInterval; // eax
  int v13; // edx
  bool v14; // cf
  unsigned int Size; // [esp-18h] [ebp-3Ch]
  Scaleform::GFx::AS3::Value *Data; // [esp-14h] [ebp-38h]
  Scaleform::GFx::AS3::Value result; // [esp+4h] [ebp-20h] BYREF
  Scaleform::GFx::AS3::Value _this; // [esp+14h] [ebp-10h] BYREF

  if ( !this->Active )
    return 0;
  pObject = proot->pASMovieRoot.pObject;
  TimeElapsed = proot->TimeElapsed;
  TimeElapsed_high = HIDWORD(proot->TimeElapsed);
  v4 = 0;
  if ( __PAIR64__(TimeElapsed_high, TimeElapsed) >= this->InvokeTime )
  {
    v8 = this->TimerObj.pObject;
    if ( v8 )
    {
      RepeatCount = this->RepeatCount;
      if ( !RepeatCount || this->CurrentCount < RepeatCount )
      {
        ++this->CurrentCount;
        Scaleform::GFx::AS3::Instances::fl_utils::Timer::ExecuteEvent(v8);
      }
    }
    else
    {
      Data = this->Params.Data.Data;
      Size = this->Params.Data.Size;
      _this.Flags = 0;
      _this.Bonus.pWeakProxy = 0;
      result.Flags = 0;
      result.Bonus.pWeakProxy = 0;
      v10 = (Scaleform::GFx::AS3::VM *)pObject[2].__vftable;
      Scaleform::GFx::AS3::VM::ExecuteInternalUnsafe(v10, &this->Function, &_this, &result, Size, Data, 0);
      if ( v10->HandleException )
        Scaleform::GFx::AS3::VM::OutputAndIgnoreException(v10);
      Scaleform::GFx::AS3::Value::~Value(&result);
      Scaleform::GFx::AS3::Value::~Value(&_this);
    }
    if ( this->Timeout || (v11 = this->RepeatCount) != 0 && this->CurrentCount >= v11 )
    {
      this->Active = 0;
      return 1;
    }
    else
    {
      NextInterval = Scaleform::GFx::AS3::IntervalTimer::GetNextInterval(
                       this,
                       __PAIR64__(TimeElapsed_high, TimeElapsed),
                       (unsigned __int64)(frameTime * 1000000.0));
      if ( v13 || NextInterval )
      {
        v14 = __CFADD__(NextInterval, this->InvokeTime);
        LODWORD(this->InvokeTime) += NextInterval;
        HIDWORD(this->InvokeTime) += v13 + v14;
        return 1;
      }
      else
      {
        HIDWORD(this->InvokeTime) = TimeElapsed_high;
        LODWORD(this->InvokeTime) = TimeElapsed;
        return 1;
      }
    }
  }
  return v4;
}
