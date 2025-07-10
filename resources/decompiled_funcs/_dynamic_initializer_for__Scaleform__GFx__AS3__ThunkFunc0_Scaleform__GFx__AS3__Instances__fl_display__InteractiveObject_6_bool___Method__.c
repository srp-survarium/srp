void (__thiscall *dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject_6_bool_::Method__())(Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject *this, bool *result)
{
  void (__thiscall *result)(Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject *, bool *); // eax

  result = Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject::mouseEnabledGet;
  LODWORD(Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject,6,bool>::Method) = Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject::mouseEnabledGet;
  dword_AAE0A4 = 0;
  return result;
}
