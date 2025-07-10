void __thiscall Scaleform::GFx::AS3::Instances::fl_events::PressAndTapGestureEvent::tapLocalYGet(
        Scaleform::GFx::AS3::Instances::fl_events::PressAndTapGestureEvent *this,
        long double *result)
{
  Scaleform::GFx::AS3::Instances::fl_events::PressAndTapGestureEvent::InitLocalCoords(this);
  *result = this->TapLocalY * 0.05;
}
