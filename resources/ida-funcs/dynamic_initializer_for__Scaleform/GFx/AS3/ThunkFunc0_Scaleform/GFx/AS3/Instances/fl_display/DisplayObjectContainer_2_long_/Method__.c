void (__thiscall *dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl_display::DisplayObjectContainer_2_long_::Method__())(Scaleform::GFx::AS3::Instances::fl_display::Stage *this, int *result)
{
  void (__thiscall *result)(Scaleform::GFx::AS3::Instances::fl_display::Stage *, int *); // eax

  result = Scaleform::GFx::AS3::Instances::fl_display::DisplayObjectContainer::numChildrenGet;
  LODWORD(Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::DisplayObjectContainer,2,long>::Method) = Scaleform::GFx::AS3::Instances::fl_display::DisplayObjectContainer::numChildrenGet;
  dword_8F2F24 = 0;
  return result;
}
