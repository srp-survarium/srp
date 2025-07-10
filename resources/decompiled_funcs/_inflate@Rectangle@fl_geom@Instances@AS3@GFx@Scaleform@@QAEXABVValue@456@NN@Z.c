void __thiscall Scaleform::GFx::AS3::Instances::fl_geom::Rectangle::inflate(
        Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *this,
        const Scaleform::GFx::AS3::Value *result,
        long double dx,
        long double dy)
{
  this->x = this->x - dx;
  this->width = dx * 2.0 + this->width;
  this->y = this->y - dy;
  this->height = 2.0 * dy + this->height;
}
