void (__thiscall *dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D_15_bool_::Method__())(Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D *this, bool *result)
{
  void (__thiscall *result)(Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D *, bool *); // eax

  result = Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D::invert;
  LODWORD(Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D,15,bool>::Method) = Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D::invert;
  dword_AAC9AC = 0;
  return result;
}
