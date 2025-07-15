void __thiscall Scaleform::GFx::AS3::Instances::fl_events::TouchEvent::sizeYGet(
        Scaleform::GFx::AS3::Instances::fl_events::TouchEvent *this,
        long double *result)
{
  Scaleform::GFx::AS3::Instances::fl_events::TouchEvent::InitLocalCoords(this);
  *result = this->SizeY * 0.05;
}
