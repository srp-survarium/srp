void __thiscall Scaleform::GFx::AS3::Instances::fl_events::GestureEvent::localXSet(
        Scaleform::GFx::AS3::Instances::fl_events::GestureEvent *this,
        const Scaleform::GFx::AS3::Value *result,
        long double value)
{
  Scaleform::GFx::AS3::Instances::fl_events::GestureEvent::InitLocalCoords(this);
  this->LocalX = value * 20.0;
}
