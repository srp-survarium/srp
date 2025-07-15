void __thiscall Scaleform::GFx::AS3::Instances::fl_geom::Rectangle::leftSet(
        Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *this,
        const Scaleform::GFx::AS3::Value *result,
        long double value)
{
  this->width = this->x - value + this->width;
  this->x = value;
}
