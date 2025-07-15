void __thiscall Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D::determinantGet(
        Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D *this,
        long double *result)
{
  *result = Scaleform::Render::Matrix4x4<double>::GetDeterminant(&this->mat4);
}
