void (__thiscall *dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Classes::fl_ui::Mouse_1_Scaleform::GFx::ASString_::Method__())(Scaleform::GFx::AS3::Classes::fl_ui::Mouse *this, Scaleform::GFx::ASString *result)
{
  void (__thiscall *result)(Scaleform::GFx::AS3::Classes::fl_ui::Mouse *, Scaleform::GFx::ASString *); // eax

  result = Scaleform::GFx::AS3::Classes::fl_ui::Mouse::cursorGet;
  LODWORD(Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_ui::Mouse,1,Scaleform::GFx::ASString>::Method) = Scaleform::GFx::AS3::Classes::fl_ui::Mouse::cursorGet;
  dword_8F280C = 0;
  return result;
}
