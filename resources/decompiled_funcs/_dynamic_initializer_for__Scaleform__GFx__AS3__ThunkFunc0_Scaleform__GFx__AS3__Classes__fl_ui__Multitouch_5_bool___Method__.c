void (__thiscall *dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Classes::fl_ui::Multitouch_5_bool_::Method__())(Scaleform::GFx::AS3::Classes::fl_ui::Multitouch *this, bool *result)
{
  void (__thiscall *result)(Scaleform::GFx::AS3::Classes::fl_ui::Multitouch *, bool *); // eax

  result = Scaleform::GFx::AS3::Classes::fl_ui::Multitouch::supportsTouchEventsGet;
  LODWORD(Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_ui::Multitouch,5,bool>::Method) = Scaleform::GFx::AS3::Classes::fl_ui::Multitouch::supportsTouchEventsGet;
  dword_AAE02C = 0;
  return result;
}
