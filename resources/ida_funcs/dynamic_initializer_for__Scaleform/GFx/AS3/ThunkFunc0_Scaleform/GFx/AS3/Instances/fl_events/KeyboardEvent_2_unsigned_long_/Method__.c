void (__thiscall *dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl_events::KeyboardEvent_2_unsigned_long_::Method__())(Scaleform::GFx::AS3::Instances::fl_events::KeyboardEvent *this, unsigned int *result)
{
  void (__thiscall *result)(Scaleform::GFx::AS3::Instances::fl_events::KeyboardEvent *, unsigned int *); // eax

  result = Scaleform::GFx::AS3::Instances::fl_events::KeyboardEvent::charCodeGet;
  LODWORD(Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::KeyboardEvent,2,unsigned long>::Method) = Scaleform::GFx::AS3::Instances::fl_events::KeyboardEvent::charCodeGet;
  dword_AADB34 = 0;
  return result;
}
