void __thiscall Scaleform::GFx::AS3::Instances::fl_geom::Vector3D::normalize(
        Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *this,
        long double *result)
{
  long double v2; // st7

  v2 = sqrt(this->y * this->y + this->x * this->x + this->z * this->z);
  *result = v2;
  this->x = this->x / v2;
  this->y = this->y / *result;
  this->z = this->z / *result;
}
