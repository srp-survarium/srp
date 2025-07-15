Scaleform::GFx::AS3::Instances::fl_events::StageOrientationEvent *__thiscall Scaleform::GFx::AS3::Instances::fl_events::StageOrientationEvent::`vector deleting destructor'(
        Scaleform::GFx::AS3::Instances::fl_events::StageOrientationEvent *this,
        char a2)
{
  Scaleform::GFx::AS3::Instances::fl_events::StageOrientationEvent::~StageOrientationEvent(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
