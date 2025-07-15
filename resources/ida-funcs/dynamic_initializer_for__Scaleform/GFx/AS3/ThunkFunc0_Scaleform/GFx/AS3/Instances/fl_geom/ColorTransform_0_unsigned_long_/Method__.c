void (__thiscall *dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl_geom::ColorTransform_0_unsigned_long_::Method__())(Scaleform::GFx::AS3::Instances::fl_geom::ColorTransform *this, unsigned int *result)
{
  void (__thiscall *result)(Scaleform::GFx::AS3::Instances::fl_geom::ColorTransform *, unsigned int *); // eax

  result = Scaleform::GFx::AS3::Instances::fl_geom::ColorTransform::colorGet;
  LODWORD(Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_geom::ColorTransform,0,unsigned long>::Method) = Scaleform::GFx::AS3::Instances::fl_geom::ColorTransform::colorGet;
  dword_8F1264 = 0;
  return result;
}
