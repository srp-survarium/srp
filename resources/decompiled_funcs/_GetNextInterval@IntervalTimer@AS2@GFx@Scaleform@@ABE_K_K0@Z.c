int __thiscall Scaleform::GFx::AS2::IntervalTimer::GetNextInterval(
        Scaleform::GFx::AS2::IntervalTimer *this,
        unsigned __int64 currentTime,
        unsigned __int64 frameTime)
{
  __int64 v3; // rdi
  __int64 v4; // rax

  LODWORD(v3) = HIDWORD(this->Interval);
  HIDWORD(v3) = this->Interval;
  if ( __PAIR64__(v3, HIDWORD(v3)) < frameTime / 0xA )
  {
    HIDWORD(v3) = frameTime / 0xA;
    LODWORD(v3) = 0;
  }
  if ( v3 )
    return (currentTime + __PAIR64__(v3, HIDWORD(v3)) - this->InvokeTime)
         / __PAIR64__(v3, HIDWORD(v3))
         * __PAIR64__(v3, HIDWORD(v3));
  else
    LODWORD(v4) = 0;
  return v4;
}
