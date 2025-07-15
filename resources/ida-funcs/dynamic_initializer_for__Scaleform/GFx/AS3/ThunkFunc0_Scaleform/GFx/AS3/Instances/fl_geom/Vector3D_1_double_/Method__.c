void (__thiscall *dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl_geom::Vector3D_1_double_::Method__())(Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *this, long double *result)
{
  void (__thiscall *result)(Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *, long double *); // eax

  result = Scaleform::GFx::AS3::Instances::fl_geom::Vector3D::lengthSquaredGet;
  LODWORD(Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D,1,double>::Method) = Scaleform::GFx::AS3::Instances::fl_geom::Vector3D::lengthSquaredGet;
  dword_8F107C = 0;
  return result;
}
