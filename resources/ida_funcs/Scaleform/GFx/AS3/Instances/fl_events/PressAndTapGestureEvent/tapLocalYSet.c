void __thiscall Scaleform::GFx::AS3::Instances::fl_events::PressAndTapGestureEvent::tapLocalYSet(
        Scaleform::GFx::AS3::Instances::fl_events::PressAndTapGestureEvent *this,
        const Scaleform::GFx::AS3::Value *result,
        long double value)
{
  Scaleform::GFx::AS3::Instances::fl_events::PressAndTapGestureEvent::InitLocalCoords(this);
  this->TapLocalY = value * 20.0;
}
