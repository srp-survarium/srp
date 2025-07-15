void __thiscall Scaleform::GFx::AS3::Instances::fl_events::PressAndTapGestureEvent::tapLocalXGet(
        Scaleform::GFx::AS3::Instances::fl_events::PressAndTapGestureEvent *this,
        long double *result)
{
  Scaleform::GFx::AS3::Instances::fl_events::PressAndTapGestureEvent::InitLocalCoords(this);
  *result = this->TapLocalX * 0.05;
}
