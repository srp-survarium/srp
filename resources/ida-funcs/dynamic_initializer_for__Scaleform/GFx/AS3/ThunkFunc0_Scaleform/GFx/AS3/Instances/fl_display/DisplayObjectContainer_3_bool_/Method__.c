void (__thiscall *dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl_display::DisplayObjectContainer_3_bool_::Method__())(Scaleform::GFx::AS3::Instances::fl_display::DisplayObjectContainer *this, bool *result)
{
  void (__thiscall *result)(Scaleform::GFx::AS3::Instances::fl_display::DisplayObjectContainer *, bool *); // eax

  result = Scaleform::GFx::AS3::Instances::fl_display::DisplayObjectContainer::tabChildrenGet;
  LODWORD(Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::DisplayObjectContainer,3,bool>::Method) = Scaleform::GFx::AS3::Instances::fl_display::DisplayObjectContainer::tabChildrenGet;
  dword_8F30DC = 0;
  return result;
}
