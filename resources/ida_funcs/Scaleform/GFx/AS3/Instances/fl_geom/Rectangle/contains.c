void __thiscall Scaleform::GFx::AS3::Instances::fl_geom::Rectangle::contains(
        Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *this,
        bool *result,
        long double x,
        long double y)
{
  *result = x < this->width + this->x && x >= this->x && y < this->height + this->y && y >= this->y;
}
