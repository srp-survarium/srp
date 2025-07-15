void (__thiscall *dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl_events::GestureEvent_2_bool_::Method__())(Scaleform::GFx::AS3::Instances::fl_events::TouchEvent *this, bool *result)
{
  void (__thiscall *result)(Scaleform::GFx::AS3::Instances::fl_events::TouchEvent *, bool *); // eax

  result = Scaleform::GFx::AS3::Instances::fl_events::GestureEvent::commandKeyGet;
  LODWORD(Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::GestureEvent,2,bool>::Method) = Scaleform::GFx::AS3::Instances::fl_events::GestureEvent::commandKeyGet;
  dword_8F2104 = 0;
  return result;
}
