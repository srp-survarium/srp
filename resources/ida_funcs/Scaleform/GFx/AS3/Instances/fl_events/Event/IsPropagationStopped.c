BOOL __thiscall Scaleform::GFx::AS3::Instances::fl_events::Event::IsPropagationStopped(
        Scaleform::GFx::AS3::Instances::fl_events::Event *this)
{
  return (*((_BYTE *)this + 48) & 0x18) != 0;
}
