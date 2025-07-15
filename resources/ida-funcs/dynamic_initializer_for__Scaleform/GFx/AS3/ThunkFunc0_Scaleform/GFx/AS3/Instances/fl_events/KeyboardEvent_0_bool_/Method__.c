void (__thiscall *dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl_events::KeyboardEvent_0_bool_::Method__())(Scaleform::GFx::AS3::Instances::fl_events::KeyboardEvent *this, bool *result)
{
  void (__thiscall *result)(Scaleform::GFx::AS3::Instances::fl_events::KeyboardEvent *, bool *); // eax

  result = Scaleform::GFx::AS3::Instances::fl_events::KeyboardEvent::altKeyGet;
  LODWORD(Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::KeyboardEvent,0,bool>::Method) = Scaleform::GFx::AS3::Instances::fl_events::KeyboardEvent::altKeyGet;
  dword_8F2354 = 0;
  return result;
}
