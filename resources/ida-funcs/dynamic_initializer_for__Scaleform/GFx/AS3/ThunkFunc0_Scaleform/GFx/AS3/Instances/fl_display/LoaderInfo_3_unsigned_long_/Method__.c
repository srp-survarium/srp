void (__thiscall *dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo_3_unsigned_long_::Method__())(Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo *this, unsigned int *result)
{
  void (__thiscall *result)(Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo *, unsigned int *); // eax

  result = Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo::bytesLoadedGet;
  LODWORD(Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo,3,unsigned long>::Method) = Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo::bytesLoadedGet;
  dword_8F2D9C = 0;
  return result;
}
