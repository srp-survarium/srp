void (__thiscall *dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl_display::DisplayObjectContainer_0_bool_::Method__())(Scaleform::GFx::AS3::Instances::fl_display::Stage *this, bool *result)
{
  void (__thiscall *result)(Scaleform::GFx::AS3::Instances::fl_display::Stage *, bool *); // eax

  result = Scaleform::GFx::AS3::Instances::fl_display::DisplayObjectContainer::mouseChildrenGet;
  LODWORD(Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::DisplayObjectContainer,0,bool>::Method) = Scaleform::GFx::AS3::Instances::fl_display::DisplayObjectContainer::mouseChildrenGet;
  dword_AAE564 = 0;
  return result;
}
