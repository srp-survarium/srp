void (__thiscall *dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Classes::fl_ui::Multitouch_2_long_::Method__())(Scaleform::GFx::AS3::Classes::fl_ui::Multitouch *this, int *result)
{
  void (__thiscall *result)(Scaleform::GFx::AS3::Classes::fl_ui::Multitouch *, int *); // eax

  result = Scaleform::GFx::AS3::Classes::fl_ui::Multitouch::maxTouchPointsGet;
  LODWORD(Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_ui::Multitouch,2,long>::Method) = Scaleform::GFx::AS3::Classes::fl_ui::Multitouch::maxTouchPointsGet;
  dword_8F2794 = 0;
  return result;
}
