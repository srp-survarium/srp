void __thiscall Scaleform::GFx::AS3::Instances::fl_events::TouchEvent::sizeXSet(
        Scaleform::GFx::AS3::Instances::fl_events::TouchEvent *this,
        const Scaleform::GFx::AS3::Value *result,
        long double value)
{
  Scaleform::GFx::AS3::Instances::fl_events::TouchEvent::InitLocalCoords(this);
  this->SizeX = value * 20.0;
}
