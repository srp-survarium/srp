void __thiscall Scaleform::GFx::AS3::Instances::fl_events::StageOrientationEvent::~StageOrientationEvent(
        Scaleform::GFx::AS3::Instances::fl_events::StageOrientationEvent *this)
{
  unsigned int Flags; // eax
  Scaleform::GFx::AS3::Value *p_AfterOrientation; // ecx
  Scaleform::GFx::AS3::Value *p_BeforeOrientation; // ecx

  Flags = this->AfterOrientation.Flags;
  p_AfterOrientation = &this->AfterOrientation;
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(p_AfterOrientation);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(p_AfterOrientation);
  }
  p_BeforeOrientation = &this->BeforeOrientation;
  if ( (this->BeforeOrientation.Flags & 0x1F) > 9 )
  {
    if ( (this->BeforeOrientation.Flags & 0x200) != 0 )
    {
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(p_BeforeOrientation);
      Scaleform::GFx::AS3::Instances::fl_events::Event::~Event(this);
      return;
    }
    Scaleform::GFx::AS3::Value::ReleaseInternal(p_BeforeOrientation);
  }
  Scaleform::GFx::AS3::Instances::fl_events::Event::~Event(this);
}
