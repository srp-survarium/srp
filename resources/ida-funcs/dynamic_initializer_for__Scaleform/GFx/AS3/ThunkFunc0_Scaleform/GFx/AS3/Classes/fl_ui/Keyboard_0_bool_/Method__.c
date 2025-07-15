void (__thiscall *dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Classes::fl_ui::Keyboard_0_bool_::Method__())(Scaleform::GFx::AS3::Classes::fl_ui::Keyboard *this, bool *result)
{
  void (__thiscall *result)(Scaleform::GFx::AS3::Classes::fl_ui::Keyboard *, bool *); // eax

  result = Scaleform::GFx::AS3::Classes::fl_ui::Keyboard::capsLockGet;
  LODWORD(Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_ui::Keyboard,0,bool>::Method) = Scaleform::GFx::AS3::Classes::fl_ui::Keyboard::capsLockGet;
  dword_8F27FC = 0;
  return result;
}
