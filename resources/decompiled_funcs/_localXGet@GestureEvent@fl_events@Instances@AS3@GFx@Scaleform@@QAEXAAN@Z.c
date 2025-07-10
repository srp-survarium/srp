void __thiscall Scaleform::GFx::AS3::Instances::fl_events::GestureEvent::localXGet(
        Scaleform::GFx::AS3::Instances::fl_events::GestureEvent *this,
        long double *result)
{
  Scaleform::GFx::AS3::Instances::fl_events::GestureEvent::InitLocalCoords(this);
  *result = this->LocalX * 0.05;
}
