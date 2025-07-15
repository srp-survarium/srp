void (__thiscall *dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl_display::Stage_16_bool_::Method__())(Scaleform::GFx::AS3::Instances::fl_display::Stage *this, bool *result)
{
  void (__thiscall *result)(Scaleform::GFx::AS3::Instances::fl_display::Stage *, bool *); // eax

  result = Scaleform::GFx::AS3::Instances::fl_display::DisplayObjectContainer::mouseChildrenGet;
  LODWORD(Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::Stage,16,bool>::Method) = Scaleform::GFx::AS3::Instances::fl_display::DisplayObjectContainer::mouseChildrenGet;
  dword_8F2E1C = 0;
  return result;
}
