void __thiscall Scaleform::GFx::AS3::Instances::fl_events::TouchEvent::localXSet(
        Scaleform::GFx::AS3::Instances::fl_events::TouchEvent *this,
        const Scaleform::GFx::AS3::Value *result,
        long double value)
{
  Scaleform::GFx::AS3::Instances::fl_events::TouchEvent::InitLocalCoords(this);
  this->LocalX = value * 20.0;
}
