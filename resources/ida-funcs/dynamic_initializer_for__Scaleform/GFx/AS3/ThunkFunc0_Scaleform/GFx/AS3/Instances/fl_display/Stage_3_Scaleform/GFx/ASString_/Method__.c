void (__thiscall *dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl_display::Stage_3_Scaleform::GFx::ASString_::Method__())(Scaleform::GFx::AS3::Instances::fl_display::Stage *this, Scaleform::GFx::ASString *result)
{
  void (__thiscall *result)(Scaleform::GFx::AS3::Instances::fl_display::Stage *, Scaleform::GFx::ASString *); // eax

  result = Scaleform::GFx::AS3::Instances::fl_display::Stage::deviceOrientationGet;
  LODWORD(Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::Stage,3,Scaleform::GFx::ASString>::Method) = Scaleform::GFx::AS3::Instances::fl_display::Stage::deviceOrientationGet;
  dword_8F299C = 0;
  return result;
}
