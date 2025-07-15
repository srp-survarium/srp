void __thiscall Scaleform::GFx::AS3::Instances::fl_geom::Vector3D::project(
        Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *this,
        const Scaleform::GFx::AS3::Value *result)
{
  this->x = this->x / this->w;
  this->y = this->y / this->w;
  this->z = this->z / this->w;
}
