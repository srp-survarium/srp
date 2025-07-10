void (__thiscall *dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl_events::TouchEvent_8_bool_::Method__())(Scaleform::GFx::AS3::Instances::fl_events::TouchEvent *this, bool *result)
{
  void (__thiscall *result)(Scaleform::GFx::AS3::Instances::fl_events::TouchEvent *, bool *); // eax

  result = Scaleform::GFx::AS3::Instances::fl_events::TouchEvent::isPrimaryTouchPointGet;
  LODWORD(Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::TouchEvent,8,bool>::Method) = Scaleform::GFx::AS3::Instances::fl_events::TouchEvent::isPrimaryTouchPointGet;
  dword_AADA4C = 0;
  return result;
}
