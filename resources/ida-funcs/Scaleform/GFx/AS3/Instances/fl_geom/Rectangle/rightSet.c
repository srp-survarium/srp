void __thiscall Scaleform::GFx::AS3::Instances::fl_geom::Rectangle::rightSet(
        Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *this,
        const Scaleform::GFx::AS3::Value *result,
        long double value)
{
  this->width = value - this->x;
}
