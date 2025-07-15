void __thiscall Scaleform::GFx::AS3::Instances::fl_events::TransformGestureEvent::offsetYGet(
        Scaleform::GFx::AS3::Instances::fl_events::TransformGestureEvent *this,
        long double *result)
{
  Scaleform::GFx::AS3::Instances::fl_events::TransformGestureEvent::InitLocalCoords(this);
  *result = this->LocalOffsetY * 0.05;
}
