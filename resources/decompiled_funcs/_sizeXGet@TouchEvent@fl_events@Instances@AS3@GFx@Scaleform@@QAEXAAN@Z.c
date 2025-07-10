void __thiscall Scaleform::GFx::AS3::Instances::fl_events::TouchEvent::sizeXGet(
        Scaleform::GFx::AS3::Instances::fl_events::TouchEvent *this,
        long double *result)
{
  Scaleform::GFx::AS3::Instances::fl_events::TouchEvent::InitLocalCoords(this);
  *result = this->SizeX * 0.05;
}
