void __thiscall Scaleform::GFx::AS3::Instances::fl_geom::Vector3D::scaleBy(
        Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *this,
        const Scaleform::GFx::AS3::Value *result,
        long double s)
{
  this->x = s * this->x;
  this->y = s * this->y;
  this->z = s * this->z;
}
