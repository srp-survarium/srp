void (__thiscall *dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc1_Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager_12_unsigned_long_unsigned_long_::Method__())(Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager *this, unsigned int *result, unsigned int controllerIdx)
{
  void (__thiscall *result)(Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager *, unsigned int *, unsigned int); // eax

  result = Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager::getControllerFocusGroup;
  LODWORD(Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager,12,unsigned long,unsigned long>::Method) = Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager::getControllerFocusGroup;
  dword_AAEB4C = 0;
  return result;
}
