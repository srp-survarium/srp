void __thiscall Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter::highlightColorGet(
        Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter *this,
        unsigned int *result)
{
  *result = this->GetBevelFilterData(this)->Params.Colors[1].Raw & 0xFFFFFF;
}
