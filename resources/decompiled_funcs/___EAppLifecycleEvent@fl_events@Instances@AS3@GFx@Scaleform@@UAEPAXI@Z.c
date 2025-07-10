Scaleform::GFx::AS3::Instances::fl_events::AppLifecycleEvent *__thiscall Scaleform::GFx::AS3::Instances::fl_events::AppLifecycleEvent::`vector deleting destructor'(
        Scaleform::GFx::AS3::Instances::fl_events::AppLifecycleEvent *this,
        char a2)
{
  unsigned int Flags; // eax
  Scaleform::GFx::AS3::Value *p_Status; // ecx

  Flags = this->Status.Flags;
  p_Status = &this->Status;
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(p_Status);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(p_Status);
  }
  Scaleform::GFx::AS3::Instances::fl_events::Event::~Event(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
