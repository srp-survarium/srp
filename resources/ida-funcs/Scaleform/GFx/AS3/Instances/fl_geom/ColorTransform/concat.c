void __thiscall Scaleform::GFx::AS3::Instances::fl_geom::ColorTransform::concat(
        Scaleform::GFx::AS3::Instances::fl_geom::ColorTransform *this,
        const Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Instances::fl_geom::ColorTransform *second)
{
  this->redOffset = second->redOffset * this->redMultiplier + this->redOffset;
  this->blueOffset = second->blueOffset * this->blueMultiplier + this->blueOffset;
  this->greenOffset = second->greenOffset * this->greenMultiplier + this->greenOffset;
  this->alphaOffset = second->alphaOffset * this->alphaMultiplier + this->alphaOffset;
  this->redMultiplier = second->redMultiplier * this->redMultiplier;
  this->greenMultiplier = second->greenMultiplier * this->greenMultiplier;
  this->blueMultiplier = second->blueMultiplier * this->blueMultiplier;
  this->alphaMultiplier = second->alphaMultiplier * this->alphaMultiplier;
}
