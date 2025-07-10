void __thiscall Scaleform::GFx::AS3::Instances::fl_geom::ColorTransform::colorSet(
        Scaleform::GFx::AS3::Instances::fl_geom::ColorTransform *this,
        const Scaleform::GFx::AS3::Value *result,
        unsigned int value)
{
  this->blueMultiplier = 0.0;
  this->greenMultiplier = 0.0;
  this->redMultiplier = 0.0;
  this->redOffset = (double)BYTE2(value);
  this->greenOffset = (double)BYTE1(value);
  this->blueOffset = (double)(unsigned __int8)value;
}
