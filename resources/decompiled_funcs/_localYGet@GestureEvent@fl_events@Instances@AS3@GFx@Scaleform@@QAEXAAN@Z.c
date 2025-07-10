void __thiscall Scaleform::GFx::AS3::Instances::fl_events::GestureEvent::localYGet(
        Scaleform::GFx::AS3::Instances::fl_events::GestureEvent *this,
        long double *result)
{
  Scaleform::GFx::AS3::Instances::fl_events::GestureEvent::InitLocalCoords(this);
  *result = this->LocalY * 0.05;
}
