Scaleform::GFx::AS3::Instances::fl_gfx::GamePadAnalogEvent *__thiscall Scaleform::GFx::AS3::Instances::fl_events::TransformGestureEvent::`scalar deleting destructor'(
        Scaleform::GFx::AS3::Instances::fl_gfx::GamePadAnalogEvent *this,
        char a2)
{
  Scaleform::GFx::AS3::Instances::fl_events::Event::~Event(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
