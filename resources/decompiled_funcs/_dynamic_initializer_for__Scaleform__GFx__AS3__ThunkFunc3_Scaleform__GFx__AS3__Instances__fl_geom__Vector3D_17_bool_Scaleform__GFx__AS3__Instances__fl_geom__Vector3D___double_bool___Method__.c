void (__thiscall *dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc3_Scaleform::GFx::AS3::Instances::fl_geom::Vector3D_17_bool_Scaleform::GFx::AS3::Instances::fl_geom::Vector3D___double_bool_::Method__())(Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *this, bool *result, Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *toCompare, double tolerance, bool allFour)
{
  void (__thiscall *result)(Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *, bool *, Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *, double, bool); // eax

  result = Scaleform::GFx::AS3::Instances::fl_geom::Vector3D::nearEquals;
  LODWORD(Scaleform::GFx::AS3::ThunkFunc3<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D,17,bool,Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *,double,bool>::Method) = Scaleform::GFx::AS3::Instances::fl_geom::Vector3D::nearEquals;
  dword_AAC8B4 = 0;
  return result;
}
