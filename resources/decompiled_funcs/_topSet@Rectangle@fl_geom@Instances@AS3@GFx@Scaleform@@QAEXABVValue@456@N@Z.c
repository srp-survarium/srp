void __thiscall Scaleform::GFx::AS3::Instances::fl_geom::Rectangle::topSet(
        Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *this,
        const Scaleform::GFx::AS3::Value *result,
        long double value)
{
  this->height = this->y - value + this->height;
  this->y = value;
}
