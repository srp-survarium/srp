void __thiscall Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter::shadowColorGet(
        Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter *this,
        unsigned int *result)
{
  *result = this->GetBevelFilterData(this)->Params.Colors[0].Raw & 0xFFFFFF;
}
