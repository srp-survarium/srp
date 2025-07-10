void (__thiscall *dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl_events::ErrorEvent_0_long_::Method__())(Scaleform::GFx::AS3::Instances::fl_events::ErrorEvent *this, int *result)
{
  void (__thiscall *result)(Scaleform::GFx::AS3::Instances::fl_events::ErrorEvent *, int *); // eax

  result = Scaleform::GFx::AS3::Instances::fl_events::ErrorEvent::errorIDGet;
  LODWORD(Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::ErrorEvent,0,long>::Method) = Scaleform::GFx::AS3::Instances::fl_events::ErrorEvent::errorIDGet;
  dword_AADACC = 0;
  return result;
}
