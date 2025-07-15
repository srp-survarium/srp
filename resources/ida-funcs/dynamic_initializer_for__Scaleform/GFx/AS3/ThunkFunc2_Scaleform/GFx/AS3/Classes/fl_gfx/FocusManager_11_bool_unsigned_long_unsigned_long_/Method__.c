void (__thiscall *dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc2_Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager_11_bool_unsigned_long_unsigned_long_::Method__())(Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager *this, bool *result, unsigned int controllerIdx, unsigned int focusGroupIdx)
{
  void (__thiscall *result)(Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager *, bool *, unsigned int, unsigned int); // eax

  result = Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager::setControllerFocusGroup;
  LODWORD(Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager,11,bool,unsigned long,unsigned long>::Method) = Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager::setControllerFocusGroup;
  dword_8F346C = 0;
  return result;
}
