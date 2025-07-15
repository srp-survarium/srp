void __thiscall Scaleform::GFx::AS3::Instances::fl_events::PressAndTapGestureEvent::tapLocalXSet(
        Scaleform::GFx::AS3::Instances::fl_events::PressAndTapGestureEvent *this,
        const Scaleform::GFx::AS3::Value *result,
        long double value)
{
  Scaleform::GFx::AS3::Instances::fl_events::PressAndTapGestureEvent::InitLocalCoords(this);
  this->TapLocalX = value * 20.0;
}
