void __thiscall Scaleform::GFx::AS3::Instances::fl_events::TransformGestureEvent::offsetYSet(
        Scaleform::GFx::AS3::Instances::fl_events::TransformGestureEvent *this,
        const Scaleform::GFx::AS3::Value *result,
        long double value)
{
  Scaleform::GFx::AS3::Instances::fl_events::TransformGestureEvent::InitLocalCoords(this);
  this->LocalOffsetY = value * 20.0;
}
