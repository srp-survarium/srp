void __thiscall Scaleform::GFx::AS3::Instances::fl_events::MouseEvent::buttonDownSet(
        Scaleform::GFx::AS3::Instances::fl_events::MouseEvent *this,
        const Scaleform::GFx::AS3::Value *result,
        bool value)
{
  if ( value )
    this->ButtonsMask |= 1u;
  else
    this->ButtonsMask &= ~1u;
}
