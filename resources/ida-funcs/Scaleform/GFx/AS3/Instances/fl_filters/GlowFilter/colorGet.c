void __thiscall Scaleform::GFx::AS3::Instances::fl_filters::GlowFilter::colorGet(
        Scaleform::GFx::AS3::Instances::fl_filters::GlowFilter *this,
        unsigned int *result)
{
  *result = *(_DWORD *)&this->FilterData.pObject[2].Frozen & 0xFFFFFF;
}
