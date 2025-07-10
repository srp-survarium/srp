void __thiscall Scaleform::GFx::AS3::Instances::fl_filters::BlurFilter::qualityGet(
        Scaleform::GFx::AS3::Instances::fl_filters::GlowFilter *this,
        int *result)
{
  *result = this->FilterData.pObject[1].RefCount;
}
