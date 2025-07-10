int __thiscall Scaleform::GFx::AS3::IntervalTimer::GetNextInterval(
        Scaleform::GFx::AS3::IntervalTimer *this,
        unsigned __int64 currentTime,
        unsigned __int64 frameTime)
{
  unsigned int RepeatCount; // eax
  __int64 v4; // rax
  unsigned int Interval_high; // ebx
  unsigned int Interval; // edi

  RepeatCount = this->RepeatCount;
  if ( RepeatCount && this->CurrentCount >= RepeatCount )
  {
    LODWORD(v4) = 0;
  }
  else
  {
    Interval_high = HIDWORD(this->Interval);
    Interval = this->Interval;
    if ( __PAIR64__(Interval_high, Interval) < frameTime / 0xA )
    {
      Interval = frameTime / 0xA;
      Interval_high = 0;
    }
    if ( Interval_high | Interval )
      return (currentTime + __PAIR64__(Interval_high, Interval) - this->InvokeTime)
           / __PAIR64__(Interval_high, Interval)
           * __PAIR64__(Interval_high, Interval);
    else
      LODWORD(v4) = 0;
  }
  return v4;
}
