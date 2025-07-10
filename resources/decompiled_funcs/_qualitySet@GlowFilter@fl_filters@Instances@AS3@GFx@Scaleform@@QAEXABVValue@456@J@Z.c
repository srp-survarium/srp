void __thiscall Scaleform::GFx::AS3::Instances::fl_filters::GlowFilter::qualitySet(
        Scaleform::GFx::AS3::Instances::fl_filters::GlowFilter *this,
        const Scaleform::GFx::AS3::Value *result,
        volatile unsigned int value)
{
  if ( value >= 0xF )
    this->FilterData.pObject[1].RefCount = 15;
  else
    this->FilterData.pObject[1].RefCount = value;
}
