void (__thiscall *dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl_events::TouchEvent_16_double_::Method__())(Scaleform::GFx::AS3::Instances::fl_events::TouchEvent *this, long double *result)
{
  void (__thiscall *result)(Scaleform::GFx::AS3::Instances::fl_events::TouchEvent *, long double *); // eax

  result = Scaleform::GFx::AS3::Instances::fl_events::TouchEvent::pressureGet;
  LODWORD(Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::TouchEvent,16,double>::Method) = Scaleform::GFx::AS3::Instances::fl_events::TouchEvent::pressureGet;
  dword_AADC5C = 0;
  return result;
}
