Scaleform::GFx::ASIntervalTimerIntf *__thiscall Scaleform::GFx::ASIntervalTimerIntf::`vector deleting destructor'(
        Scaleform::GFx::ASIntervalTimerIntf *this,
        char a2)
{
  this->__vftable = (Scaleform::GFx::ASIntervalTimerIntf_vtbl *)&Scaleform::GFx::ASIntervalTimerIntf::`vftable';
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
