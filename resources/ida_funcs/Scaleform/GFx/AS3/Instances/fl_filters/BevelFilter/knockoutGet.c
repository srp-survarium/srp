void __thiscall Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter::knockoutGet(
        Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter *this,
        bool *result)
{
  *result = (this->GetBevelFilterData(this)->Params.Mode & 0x10) != 0;
}
