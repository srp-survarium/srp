void __thiscall Scaleform::GFx::AS3::Instances::fl_geom::Vector3D::lengthGet(
        Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *this,
        long double *result)
{
  *result = sqrt(this->y * this->y + this->x * this->x + this->z * this->z);
}
