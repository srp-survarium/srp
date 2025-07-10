void (__thiscall *dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D_0_double_::Method__())(Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D *this, long double *result)
{
  void (__thiscall *result)(Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D *, long double *); // eax

  result = Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D::determinantGet;
  LODWORD(Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D,0,double>::Method) = Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D::determinantGet;
  dword_AAC9F4 = 0;
  return result;
}
