void __thiscall Scaleform::GFx::AS3::Instances::fl_geom::PerspectiveProjection::PerspectiveProjection(
        Scaleform::GFx::AS3::Instances::fl_geom::PerspectiveProjection *this,
        Scaleform::GFx::AS3::InstanceTraits::Traits *t)
{
  Scaleform::GFx::AS3::Instances::fl::Object::Object(this, t);
  this->projectionCenter.x = 250.0;
  this->__vftable = (Scaleform::GFx::AS3::Instances::fl_geom::PerspectiveProjection_vtbl *)&Scaleform::GFx::AS3::Instances::fl_geom::PerspectiveProjection::`vftable';
  this->projectionCenter.y = 250.0;
  this->pDispObj = 0;
  this->fieldOfView = 55.0;
  this->focalLength = 250.0 / tan(0.4799655442984406);
}
