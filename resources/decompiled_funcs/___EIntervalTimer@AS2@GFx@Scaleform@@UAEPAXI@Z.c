Scaleform::GFx::AS2::IntervalTimer *__thiscall Scaleform::GFx::AS2::IntervalTimer::`vector deleting destructor'(
        Scaleform::GFx::AS2::IntervalTimer *this,
        char a2)
{
  Scaleform::GFx::AS2::IntervalTimer::~IntervalTimer(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
