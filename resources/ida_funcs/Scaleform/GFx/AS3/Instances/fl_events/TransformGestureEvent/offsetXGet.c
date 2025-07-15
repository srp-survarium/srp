void __thiscall Scaleform::GFx::AS3::Instances::fl_events::TransformGestureEvent::offsetXGet(
        Scaleform::GFx::AS3::Instances::fl_events::TransformGestureEvent *this,
        long double *result)
{
  Scaleform::GFx::AS3::Instances::fl_events::TransformGestureEvent::InitLocalCoords(this);
  *result = this->LocalOffsetX * 0.05;
}
