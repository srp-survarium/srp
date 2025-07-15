void (__thiscall *dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl_events::KeyboardEvent_4_bool_::Method__())(Scaleform::GFx::AS3::Instances::fl_events::KeyboardEvent *this, bool *result)
{
  void (__thiscall *result)(Scaleform::GFx::AS3::Instances::fl_events::KeyboardEvent *, bool *); // eax

  result = Scaleform::GFx::AS3::Instances::fl_events::KeyboardEvent::controlKeyGet;
  LODWORD(Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::KeyboardEvent,4,bool>::Method) = Scaleform::GFx::AS3::Instances::fl_events::KeyboardEvent::controlKeyGet;
  dword_AAD96C = 0;
  return result;
}
