void __thiscall Scaleform::GFx::AS3::Instances::fl_events::TouchEvent::localXGet(
        Scaleform::GFx::AS3::Instances::fl_events::TouchEvent *this,
        long double *result)
{
  Scaleform::GFx::AS3::Instances::fl_events::TouchEvent::InitLocalCoords(this);
  *result = this->LocalX * 0.05;
}
