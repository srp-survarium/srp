void __thiscall Scaleform::GFx::AS3::Instances::fl_geom::Rectangle::isEmpty(
        Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *this,
        bool *result)
{
  *result = this->width <= 0.0 || this->height <= 0.0;
}
