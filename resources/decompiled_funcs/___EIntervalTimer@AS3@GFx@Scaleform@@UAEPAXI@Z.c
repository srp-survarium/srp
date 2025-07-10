Scaleform::GFx::AS3::IntervalTimer *__thiscall Scaleform::GFx::AS3::IntervalTimer::`vector deleting destructor'(
        Scaleform::GFx::AS3::IntervalTimer *this,
        char a2)
{
  Scaleform::GFx::AS3::IntervalTimer::~IntervalTimer(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
