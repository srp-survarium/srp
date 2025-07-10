void (__thiscall *dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl_events::KeyboardEvent_10_unsigned_long_::Method__())(Scaleform::GFx::AS3::Instances::fl_events::KeyboardEvent *this, unsigned int *result)
{
  void (__thiscall *result)(Scaleform::GFx::AS3::Instances::fl_events::KeyboardEvent *, unsigned int *); // eax

  result = Scaleform::GFx::AS3::Instances::fl_events::KeyboardEvent::keyCodeGet;
  LODWORD(Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::KeyboardEvent,10,unsigned long>::Method) = Scaleform::GFx::AS3::Instances::fl_events::KeyboardEvent::keyCodeGet;
  dword_AAD7DC = 0;
  return result;
}
