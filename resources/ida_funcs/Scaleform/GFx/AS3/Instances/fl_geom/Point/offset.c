void __thiscall Scaleform::GFx::AS3::Instances::fl_geom::Point::offset(
        Scaleform::GFx::AS3::Instances::fl_geom::Point *this,
        const Scaleform::GFx::AS3::Value *result,
        long double dx,
        long double dy)
{
  this->x = dx + this->x;
  this->y = dy + this->y;
}
