void (__thiscall *dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl_events::ProgressEvent_0_double_::Method__())(Scaleform::GFx::AS3::Instances::fl_events::ProgressEvent *this, long double *result)
{
  void (__thiscall *result)(Scaleform::GFx::AS3::Instances::fl_events::ProgressEvent *, long double *); // eax

  result = Scaleform::GFx::AS3::Instances::fl_events::ProgressEvent::bytesLoadedGet;
  LODWORD(Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::ProgressEvent,0,double>::Method) = Scaleform::GFx::AS3::Instances::fl_events::ProgressEvent::bytesLoadedGet;
  dword_8F24F4 = 0;
  return result;
}
